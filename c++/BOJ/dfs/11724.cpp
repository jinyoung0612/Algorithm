#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int n,m;
int visited[MAX];
vector<int> graph[MAX];

void DFS(int node){

        visited[node]=1;
        for(int i=0; i<graph[node].size(); i++){
            int next=graph[node][i];
            if(!visited[next]){
                DFS(next);
            }
        }
}

int main(void){
    
    int u,v;
    int result=0;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    for(int i=1; i<=n; i++){
            if(!visited[i]){
                DFS(i);
                result++;
            }
    }
    cout<<result<<endl;


    return 0;
}