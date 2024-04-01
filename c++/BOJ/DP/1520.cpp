#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 501
int M,N;
int arr[MAX][MAX];
int dp[MAX][MAX];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int dfs(int y, int x){
    if(y==M-1&&x==N-1){
        return 1;
    }
    else if(dp[y][x]==-1){
        dp[y][x]=0;    
        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || ny>=M || nx<0 || nx>=N) continue;

            if(arr[ny][nx]<arr[y][x]){
                dp[y][x]+=dfs(ny,nx);
            }
        }
    }
    return dp[y][x];    
}
int main(void){
    cin>>M>>N;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<dfs(0,0);
   
    

    return 0;
}