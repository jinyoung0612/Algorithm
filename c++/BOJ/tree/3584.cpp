#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10001
int parent[MAX];
vector<int> graph[MAX];
int depth[MAX];

void dfs(int a, int deg){
    depth[a]=deg;
    for(int i=0; i<graph[a].size(); i++){
        dfs(graph[a][i],deg+1);
    }
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    int n;
    
    while(T--){
        cin>>n;
        int a,b;
        memset(parent,false,sizeof(parent));
        memset(depth,false,sizeof(depth));
        for(int i=0; i<MAX; i++){
            graph[i].clear();
        }
    
        for(int i=0 ;i<n-1; i++){
            cin>>a>>b;
            graph[a].push_back(b);
            parent[b]=a;
        }

        for(int i=1; i<=n; i++){
            if(!parent[i]){
                parent[i]=i;
                dfs(i,1);
                break;
            }
        }
        cin>>a>>b;
        while(depth[a]!=depth[b]){
            if(depth[a]<depth[b]){
                b=parent[b];
            }
            else{
                a=parent[a];
            }
        }
        while(a!=b){
            a=parent[a];
            b=parent[b];
        }
        cout<<a<<"\n";
    }
    
    return 0;
} 