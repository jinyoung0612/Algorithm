#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 31
long long dp[MAX][MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    int n,m;
    cin>>T;

    for(int i=1; i<31; i++){
        dp[1][i]=i;
    }

    for(int i=2; i<31; i++){
        for(int j=i; j<31; j++){
            for(int k=j-1; k>=i-1; k--){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    
    while(T--){
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";

    }
   
    return 0;
} 