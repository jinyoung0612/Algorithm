#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 9
int n,m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int temp[MAX][MAX];
int max_val=0;

void dfs(int x, int y){
    visited[x][y]=1;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
    
        if(0<=nx&&nx<n&&0<=ny&&ny<m){
            if(!visited[nx][ny]&&temp[nx][ny]==0){
                temp[nx][ny]=2;
                dfs(nx,ny);
            }
        }
    }
}

void combination(int start, int start2, int depth){
    if(depth==3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                temp[i][j]=map[i][j];
            }
        }

        memset(visited,0,sizeof(visited));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==2&&!visited[i][j]){
                    dfs(i,j);
                }
            }
        }
        int cnt=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==0){
                    cnt++;
                }
            }
        }
        max_val=max(cnt,max_val);

    
        return;
    }

    for(int i=start; i<n; i++){
        for(int j=(i==start) ? start2 : 0; j<m; j++){
            if(map[i][j]==0){
                map[i][j]=1;
                combination(i,j,depth+1);
                map[i][j]=0;
            }
        }
    }
    
}

int main(void){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    
    combination(0,0,0);
    cout<<max_val<<"\n";

    return 0;
}