#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1000+1

int N,M,V;
int adj[MAX][MAX];
bool visited[MAX];
queue<int> q;
void DFS(int idx){
    cout<<idx<<" ";
    visited[idx]=1;
    for(int i=1; i<=N; i++){
        if(adj[idx][i]&&!visited[i]){
            DFS(i);
        }
    }

}
void BFS(int idx){
    q.push(idx);
    visited[idx]=1;
    while(!q.empty()){
        idx=q.front();
        q.pop();

        cout<<idx<<" ";

        for(int i=1; i<=N; i++){
            if(adj[idx][i]&&!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
int main(void){
    

    cin>>N>>M>>V;

    for(int i=0; i<M; i++){
        int start, end;
        cin>>start>>end;
        adj[start][end]=1;
        adj[end][start]=1;
    }

    visited[V]=1;
    DFS(V);
    cout<<endl;
    memset(visited,false,sizeof(visited));
    BFS(V);
    cout<<endl;
    return 0;
}