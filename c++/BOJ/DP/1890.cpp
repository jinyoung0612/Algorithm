#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 101

int MAP[MAX][MAX];
long dp[MAX][MAX];

int n;

long dfs(int x, int y){
    if(x==n-1&&y==n-1){
        return 1;
    }
    else if(dp[x][y]==-1){
        dp[x][y]=0;

        int nx=x+MAP[x][y];
        int ny=y+MAP[x][y];

        if(ny<n){
            dp[x][y]+=dfs(x,ny);
        }
        if(nx<n){
            dp[x][y]+=dfs(nx,y);
        }

    }
    return dp[x][y];
}

int main(void){

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>MAP[i][j];
            dp[i][j]=-1;
        }
    }

    // dp[0][0]=1;
  
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(dp[i][j]==0||(i==n-1&&j==n-1)) continue;
    //         int nx=i+MAP[i][j];
    //         int ny=j+MAP[i][j];
    //         if(ny<n){
    //             dp[i][ny]+=dp[i][j];
    //         }
    //         if(nx<n){
    //             dp[nx][j]+=dp[i][j];
    //         }
    //     }
    // }

    // cout<<dp[n-1][n-1];
    cout<<dfs(0,0);

    return 0;
}