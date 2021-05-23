#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1001

int dp[MAX][3];
int cost[MAX][3];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }
    dp[0][0]=cost[0][0];
    dp[0][1]=cost[0][1];
    dp[0][2]=cost[0][2];

    for(int i=1; i<N; i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+cost[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2];
    }
    
    int answer=min(min(dp[N-1][0],dp[N-1][1]),dp[N-1][2]);
    cout<<answer;
    
    
   
    return 0;
} 