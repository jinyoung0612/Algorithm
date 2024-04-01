#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001
#define mod 10007
int dp[MAX][10];

int main(void){

    int n;
    cin>>n;
    for(int i=0; i<10; i++) dp[1][i]=1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<=9; k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
        }
    }
    int result=0;
    for(int i=0; i<10; i++){
        result=(result+dp[n][i])%mod;
    }
    cout<<result%mod;

    return 0;
}