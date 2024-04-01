#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 201
#define mod 1000000000

int dp[MAX][MAX]; //k ,n

int main(void){
    int n,k;
    cin>>n>>k;

    for(int i=0; i<=n; i++){
        dp[1][i]=1;
    }

    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int m=0; m<=j; m++){
                dp[i][j]=(dp[i][j]+dp[i-1][m])%mod;
            }
        }
    }
    cout<<dp[k][n]%mod;

   
    return 0;
}