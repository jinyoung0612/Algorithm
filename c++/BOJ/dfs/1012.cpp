#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 51

int t,m,n,k;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void DFS(int a, int b){
    visited[a][b]=1;

    for(int i=0; i<4; i++){

        int next_x=a+dx[i];
        int next_y=b+dy[i];

        if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n){
                if(map[next_x][next_y]==1&&!visited[next_x][next_y]){
                    DFS(next_x,next_y);
                }
            }
    }
}
void BFS(int a, int b){

    queue< pair<int,int> > q;

    q.push(make_pair(a,b));
    visited[a][b]=1;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
                    
        for(int k=0; k<4; k++){

            int next_x=x+dx[k];
            int next_y=y+dy[k];

            if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n){
                if(map[next_x][next_y]==1&&!visited[next_x][next_y]){
                    q.push(make_pair(next_x,next_y));
                    visited[next_x][next_y]=1;
                }
            }
        }
    }
}

int main(void){
    cin>>t;
    int x,y;

    for(int i=0; i<t; i++){
        int result=0;
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        
        cin>>m>>n>>k;
        for(int j=0; j<k; j++){
            cin>>x>>y;
            map[x][y]=1;
        }

        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                if(map[j][k]==1&&!visited[j][k]){
                    DFS(j,k);
                    result++;
                }
            }
        }
        cout<<result<<endl;
    }
    
    return 0;
}