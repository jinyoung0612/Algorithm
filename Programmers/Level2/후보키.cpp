#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define MAX 9
int clen=0;
int rlen=0;
int result[MAX];
vector<vector<string> > temp;
vector<string> ans;
bool check[MAX];

bool isPossible(string str){
    
    for(int i=0; i<ans.size(); i++){
        
        memset(check,false,sizeof(check));
        int size=ans[i].size();
        int cnt=0;
        for(int j=0; j<ans[i].size(); j++){
            check[ans[i][j]-'0']=1;
        }
        for(int j=0; j<str.size(); j++){
            if(check[str[j]-'0']){
                cnt++;
            }
        }
        if(size==cnt){
            return false;
        }
        
    }
    
    return true;
}
void combination(int depth, int start,int n){
    if(depth>=n){
        set<string> s;
        string combi="";
        
        for(int i=0; i<n; i++){
            combi+=(result[i]+'0');
        }
        
        for(int i=0; i<temp.size(); i++){
            string str="";
            for(int j=0; j<n; j++){
                str=str+temp[i][result[j]];
            }
            s.insert(str);
        }
        if(s.size()==rlen&&isPossible(combi)){
            ans.push_back(combi);
        }
        return;
    }
    
    for(int i=start; i<clen; i++){
        result[depth]=i;
        combination(depth+1,i+1,n);
    }
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    temp=relation;
    clen=relation[0].size();
    rlen=relation.size();
   
    for(int i=1; i<=clen; i++){
        combination(0,0,i);
    }

    answer=ans.size();
    
    
    return answer;
}
