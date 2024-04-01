#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size()<b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> >v;
    string str=s.substr(1,s.size()-2);
    
    for(int i=0; i<str.size(); i++){
        
        if(str[i]=='{'){
            int idx=i+1;
            string temp="";
            vector<int> vv;
            while(str[idx]!='}'){
                if(str[idx]==','){
                    vv.push_back(stoi(temp));
                    temp="";
                }
                else{
                    temp+=str[idx];
                }
                idx++;
            }
            vv.push_back(stoi(temp));
            v.push_back(vv);
        }
    }

    sort(v.begin(),v.end(),cmp);

    answer.push_back(v[0][0]);

    for(int i=1; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(find(answer.begin(),answer.end(),v[i][j])==answer.end()){
                answer.push_back(v[i][j]);
            }
        }
    }
    return answer;
}