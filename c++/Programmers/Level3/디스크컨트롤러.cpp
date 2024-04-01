#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    int time=0;
    int idx=0;
    
    while(idx<jobs.size() || !pq.empty()){
        if(idx<jobs.size()&&jobs[idx][0]<=time){

            pq.push(make_pair(jobs[idx][1],jobs[idx][0]));
            idx++;
            continue;
        }
        
        if(!pq.empty()){
            time+=pq.top().first;
            answer+=(time-pq.top().second);
            pq.pop();
        }
        else{
            time=jobs[idx][0];
        }
    }
    answer/=jobs.size();
    return answer;
}