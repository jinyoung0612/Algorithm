#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 20001

vector<int> graph[MAX];
int visited[MAX]={0,};
int K,V,E;
void dfs(int v){
    if(!visited[v]){
        visited[v]=1;
    }
    for(int i=0; i<(int)graph[v].size(); i++){
        int next=graph[v][i];
        if(!visited[next]){
            if(visited[v]==1){
                visited[next]=2;
            }
            else if(visited[v]==2){
                visited[next]=1;
            }
            dfs(next);
        }
    }
}
bool isBipartieGraph(){
    for(int i=1; i<=V; i++ ){
        for(int j=0; j<(int)graph[i].size(); j++){
            int next=graph[i][j];
            if(visited[i]==visited[next]){
                return 0;
            }
        }
    }
    return 1;
}
int main(void){
    cin>>K;
    int a,b;
    for(int i=0; i<K; i++){
        cin>>V>>E;
        for(int j=0; j<E; j++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int j=1; j<=V; j++){
            dfs(j);
        }
        if(isBipartieGraph()) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
        for(int i=1; i<=V; i++){
            graph[i].clear();
        }
        memset(visited,0,sizeof(visited));

    }
    
    return 0;
}