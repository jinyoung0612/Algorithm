#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 51
int w,h;
int adj[MAX][MAX];
bool visited[MAX][MAX]={0,};
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={1,0,-1,-1,-1,0,1,1};

void dfs(int x, int y){
   visited[x][y]=1;

   for(int i=0; i<8; i++){
       int nx=x+dx[i];
       int ny=y+dy[i];

       if(0<=nx&&nx<h&&0<=ny&&ny<w){
           if(adj[nx][ny]==1&&!visited[nx][ny]){
               dfs(nx,ny);
           }
       }
   }
}

int main(void){
    while(1){
        int cnt=0;
        cin>>w>>h;
        if(w==0&&h==0) break;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>adj[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(adj[i][j]==1&&!visited[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";

        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));


    }
    return 0;
}