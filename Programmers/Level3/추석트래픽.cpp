
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

pair<int,int> convert(string s){
    int hour=stoi(s.substr(11,2))*3600*1000;
    int minute=stoi(s.substr(14,2))*60*1000;
    int sec=stoi(s.substr(17,2))*1000;
    int msec=stoi(s.substr(20,3));
    string process=s.substr(24);
    process=process.substr(0,process.size()-1);
    
    int end=hour+minute+sec+msec;
    int start=end-(stof(process)*1000)+1;
    
    return make_pair(start,end);
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int> > v;
    for(int i=0; i<lines.size(); i++){
        v.push_back(convert(lines[i]));
    }
    
    for(int i=0; i<v.size(); i++){
        int end_time=v[i].second+1000;
        int cnt=0;
        for(int j=i; j<v.size(); j++){
            if(v[j].first<end_time) cnt++;
        }
        answer=max(answer,cnt);
    }
    return answer;
}