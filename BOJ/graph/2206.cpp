#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX][2]={0,};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct wall{
    int x, y, times;
    bool block;
};

int bfs(){
    queue<wall> q;
    wall temp={0,0,0,1};
    q.push(temp);

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int times=q.front().times;
        int block=q.front().block;

        q.pop();

        if(x==n-1&&y==m-1) return times+1;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(arr[nx][ny]==1&&block==1){
                    visited[nx][ny][0]=1;
                    wall temp2={nx,ny,times+1,0};
                    q.push(temp2);
                }
                if(arr[nx][ny]==0&&!visited[nx][ny][block]){
                    visited[nx][ny][block]=1;
                    wall temp3={nx,ny,times+1,block};
                    q.push(temp3);
                }

            }
        }
    }
   
    return -1;

}
int main(void){
    cin>>n>>m;
    string str;
    for(int i=0; i<n; i++){
        cin>>str;
        for(int j=0; j<m; j++){
            arr[i][j]=str[j]-'0';
        }
    }
    cout<<bfs();
    return 0;
}