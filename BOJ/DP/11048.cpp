#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001

int miro[MAX][MAX];
int dp[MAX][MAX];
int main(void){

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>miro[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+miro[i][j];
        }
    }

    cout<<dp[n][m];


    return 0;
}