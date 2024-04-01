#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 201

vector<pair<int,int> > graph[MAX];
int arr[MAX];
int parent[MAX];
void Dijkstra(int start){
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        int cur=pq.top().second;
        int times=pq.top().first;
        pq.pop();

        if(arr[cur]<times) continue;

        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i].second;
            int ntimes=graph[cur][i].first+times;

            if(arr[next]>ntimes){
                if(cur!=start){
                    parent[next]=cur;
                }
                arr[next]=ntimes;
                pq.push(make_pair(ntimes,next));
            }
        }
    }
    
}
int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(c,b));
        graph[b].push_back(make_pair(c,a));
    }
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[j]=987654321;
        }
        for(int j=1; j<=n; j++){
            parent[j]=j;
        }
        Dijkstra(i);
        for(int j=1; j<=n; j++){
            if(i==j){
                cout<<"- ";
            }
            else{
                cout<<getParent(j)<<" ";
            }
        }
        cout<<"\n";
    }
    
    return 0;
} 