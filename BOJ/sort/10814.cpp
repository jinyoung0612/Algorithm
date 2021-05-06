#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10001
bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first<b.first;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    string str;
    cin.ignore();
    vector<pair<int,string> > v;
    for(int i=0; i<N; i++){
        getline(cin,str);
        string temp="";
        int age=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]==' '){
                age=stoi(temp);
                temp="";
                continue;
            }
            temp+=str[i];
        }
        v.push_back(make_pair(age,temp));
    }

    stable_sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
  
    return 0;
} 