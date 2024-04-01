#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 100+1

int N,M;
char adj[MAX][MAX];
bool visited[MAX][MAX];
int check[MAX][MAX]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS(int a, int b){
    visited[a][b]=1;
    queue< pair<int,int> > q;
    q.push(make_pair(a,b));

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;

        q.pop();

        for(int i=0; i<4; i++){
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            
            if(0<=next_x&&next_x<N&&0<=next_y&&next_y<M){
                if(adj[next_x][next_y]=='1'&&visited[next_x][next_y]==0){
                    check[next_x][next_y]=check[x][y]+1;
                    visited[next_x][next_y]=1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }
}

int main(void){
    
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>adj[i];
    }
    BFS(0,0);
    cout<<check[N-1][M-1]+1;

    
    return 0;
}