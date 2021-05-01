#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> crews;
    
    sort(timetable.begin(),timetable.end());
    
    for(int i=0; i<timetable.size(); i++){
        int h=stoi(timetable[i].substr(0,2));
        int m=stoi(timetable[i].substr(3,2));
        crews.push_back(h*60+m);
    }
    
    int bus=540;
    int cnum=timetable.size();
    int idx=0;
    int result=0;
    
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=idx; j<cnum; j++){
            if(crews[idx]<=bus){
                idx++;
                cnt++;
            }
            if(cnt==m) break;
        }
        if(i==n-1){
            if(cnt==m){
                result=crews[idx-1]-1;
            }
            else{
                result=bus;
            }
        }
        bus+=t;
        if(bus>=24*60) break;
    }
    
    int hour=result/60;
    int minute=result%60;
    
    if(hour<10)answer+="0"+to_string(hour);
    else answer+=to_string(hour);
    if(minute<10)answer+=":0"+to_string(minute);
    else answer+=":"+to_string(minute);
   
    return answer;
}