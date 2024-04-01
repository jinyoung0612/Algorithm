#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
   
    sort(times.begin(),times.end());
    long long start=1;
    long long end=(long long)times[times.size()-1]*n;
     long long answer = end;
    while(start<=end){
        long long mid=(start+end)/2;

        long long temp=0;
        for(int i=0; i<times.size(); i++){
            temp+=(mid/times[i]);
        }
        if(temp<n) start=mid+1;
        else{
            answer=min(answer,mid);
            end=mid-1;
        }
    }
    return answer;
}