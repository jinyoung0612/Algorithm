#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> Genres;
unordered_map<string, int> m;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(m[Genres[a.first]]==m[Genres[b.first]]){
        return a.second>b.second;
    }
    else return m[Genres[a.first]]>m[Genres[b.first]];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    Genres=genres;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]]+=plays[i];
    }
    vector<pair<int,int> >v;
    for(int i=0; i<genres.size(); i++){
        v.push_back(make_pair(i,plays[i]));
    }
    sort(v.begin(),v.end(),cmp);
    
    string temp=genres[v[0].first];
    int cnt=1;
    answer.push_back(v[0].first);
    for(int i=1; i<v.size(); i++){
        if(temp!=genres[v[i].first]){
            temp=genres[v[i].first];
            cnt=1;
            answer.push_back(v[i].first);
        }
        else{
            if(cnt==2){
                continue;
            }
            answer.push_back(v[i].first);
            cnt++;
        }
    }
   
    
    return answer;
}