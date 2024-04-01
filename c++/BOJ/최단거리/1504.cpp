#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 801
#define INF 987654321

int N,E;

vector<pair<int,int> > graph[MAX];

vector<int> Dijstra(int start){
    
    vector<int> node(N+1,INF);
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0,start));
    node[start]=0;

    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=pq.top().first;
        pq.pop();

        if(node[cur]<cost) continue;

        for(int i=0; i<graph[cur].size(); i++){
            
            int next=graph[cur][i].first;
            int ncost=graph[cur][i].second+cost;
            
            if(node[next]>ncost){
                node[next]=ncost;
                pq.push(make_pair(ncost,next));
            }
        }
    }
    return node;
}

int main(void){
  
  
    cin>>N>>E;
    int a,b,c;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    
     
    int v1,v2;
    cin>>v1>>v2;

    vector<int> result=Dijstra(1);
    vector<int> temp1=Dijstra(v1);
    vector<int> temp2=Dijstra(v2);

    // 1->v1->v2>N or 1->v2->v1->N
    int answer=min(result[v1]+temp1[v2]+temp2[N],result[v2]+temp2[v1]+temp1[N]);
    
    // overflow 발생가능
    if(answer>=INF || answer<0){
        cout<<-1;
    }
    else{
        cout<<answer;
    }
    return 0;
}