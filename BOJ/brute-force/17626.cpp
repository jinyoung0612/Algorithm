#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 50001
int N;
int dp[MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;

    for(int i=1; i<=N; i++){
        dp[i]=i;
    }
    for(int i=1; i<=sqrt(N); i++){
        dp[i*i]=1;
    }
    
    for(int i=2; i<=N; i++){
        for(int j=1; j<=sqrt(i); j++){
            dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
        }
    }
    cout<<dp[N];
    return 0;
} 