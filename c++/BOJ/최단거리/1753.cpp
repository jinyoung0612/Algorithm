#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 20001
#define INF 987654321

int node[MAX];
vector< pair<int,int> > graph[MAX];

// Dijstra 알고리즘
int main(void){
    int V,E,K;
    cin>>V>>E;
    cin>>K;
    int u,v,w;
    
    for(int i=1; i<=V; i++){
        node[i]=INF;
    }    
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }
    node[K]=0;
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,K));
    
    while(!pq.empty()){
        int cost=pq.top().first;
        int cv=pq.top().second;
        pq.pop();

        if(node[cv]<cost) continue;

        for(int i=0; i<graph[cv].size(); i++){
            int next=graph[cv][i].first;
            int ncost=graph[cv][i].second+cost;
            
            if(node[next]>ncost){
                node[next]=ncost;
                pq.push(make_pair(ncost,next));
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(node[i]==INF) cout<<"INF\n";
        else{
            cout<<node[i]<<"\n";
        }
    }
 
    
    

    return 0;
}