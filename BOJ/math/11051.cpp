#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
#define mod 10007
int dp[MAX][MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    for(int i=1; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(i==j || j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
    }
    cout<<dp[N][K];
    
    return 0;
} 