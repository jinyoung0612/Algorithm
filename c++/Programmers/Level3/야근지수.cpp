#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int,vector<int> > pq;

    for(int i=0; i<works.size(); i++){
        pq.push(works[i]);
    }
 
    while(n>0){
        int w=pq.top();
        pq.pop();

        if(w==0) break;
        n--;
        pq.push(w-1);
        
    }

    while(!pq.empty()){
        answer+=(long long)pq.top()*(long long)pq.top();
        pq.pop();
    }
    return answer;
}