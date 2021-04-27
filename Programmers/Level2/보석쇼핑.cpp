#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second-a.first==b.second-b.first){
        return a.first<b.first;
    }
    return a.second-a.first<b.second-b.first;
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    set<string> s;
    map<string,int> m;
    
    for(int i=0; i<gems.size(); i++){
        s.insert(gems[i]);
    }
    
    int gemnum=s.size();
    int start=0;
    int end=0;
  
    vector<pair<int,int> > v;
    
    while(1){
        if(m.size()==gemnum){
            v.push_back(make_pair(start,end-1));
            
            if(m[gems[start]]==start){
                m.erase(gems[start]);
            }
            start++;
        }
        else{
            if(end>=gems.size()) break;
            m[gems[end]]=end;
            end++;
        }
    }
    
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

    sort(v.begin(),v.end(),cmp);
    answer.push_back(v[0].first+1);
    answer.push_back(v[0].second+1);
    return answer;
}