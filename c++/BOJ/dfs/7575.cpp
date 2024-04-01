#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int m,n;
int arr[MAX][MAX];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int visited[MAX][MAX];
queue< pair<int, int> > q;

void bfs(){

    while(!q.empty()){

        int qx=q.front().first;
        int qy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){

            int nx=qx+dx[i];
            int ny=qy+dy[i];

            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                if(arr[nx][ny]==0){
                    arr[nx][ny]=arr[qx][qy]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    
    }
    

}

int main(void){
    int cnt=0;
    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }

    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(arr[i][j]==1){
    //             q.push(make_pair(i,j));
    //             visited[i][j]=0;
    //         }
    //     }
    // }
    bfs();

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cnt=max(cnt,visited[i][j]);
    //     }
    // }

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0){
                cout<<"-1\n";
                return 0;
            }
            if(cnt<arr[i][j]){
                cnt=arr[i][j];
            }
        }
    }
    

    cout<<cnt-1;

    
    return 0;
}