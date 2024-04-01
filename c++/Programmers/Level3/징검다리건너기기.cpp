#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define INF 200000000
int solution(vector<int> stones, int k) {
    int answer = 0;
 
    int start=1;
    int end=INF;
    
    while(start<=end){
        
        int mid=(start+end)/2;
        int cnt=0;
        bool flag=true;
        
        for(int i=0; i<stones.size(); i++){
            //연속으로 mid보다 작은 경우 check
            if(stones[i]<mid){
                cnt+=1;
                if(cnt>=k){
                    flag=false;
                }
            }
            else{
                cnt=0;
            }
        }
        
        
        if(flag){
            cout<<mid<<" ";
            start=mid+1;
            answer=max(answer,mid);
        }
        else{
            end=mid-1;
        }
        
    }
   
    return answer;
}