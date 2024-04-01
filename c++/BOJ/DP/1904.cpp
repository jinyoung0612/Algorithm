#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000001
#define mod 15746
int dp[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3; i<=N; i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    cout<<dp[N];

   
    return 0;
} 