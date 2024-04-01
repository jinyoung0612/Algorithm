#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 91

long long dp[MAX][2];

int main(void){
    int n;
    cin>>n;

    dp[1][0]=0;
    dp[1][1]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<2; j++){
            if(j==0){
                dp[i][j]=dp[i-1][0]+dp[i-1][1];
            }
            else if(j==1){
                dp[i][j]=dp[i-1][0];
            } 
        }
    }
    cout<<dp[n][0]+dp[n][1];
   

    return 0;
}