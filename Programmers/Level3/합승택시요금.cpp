#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define MAX 201
#define INF 6e8
int N;
vector<pair<int,int> > graph[MAX];
vector<int> Dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    vector<int> node(N+1,INF);
    
    pq.push(make_pair(0,start));
    node[start]=0;
    
    while(!pq.empty()){
        int cur=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        
        if(node[cur]<cost) continue;
        
        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i].second;
            int ncost=graph[cur][i].first+cost;
            if(ncost<node[next]){
                node[next]=ncost;
                pq.push(make_pair(ncost,next));
            }
            
        }
    }
    return node;
}
int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = INF;
    N=n;

    for(int i=0; i<fares.size(); i++){
        graph[fares[i][0]].push_back(make_pair(fares[i][2],fares[i][1]));
        graph[fares[i][1]].push_back(make_pair(fares[i][2],fares[i][0]));
    }
    
    vector<int> result=Dijkstra(s);
    
    for(int i=1; i<=n; i++){
        vector<int> temp=Dijkstra(i);
        int cost=result[i]+temp[a]+temp[b];
        if(cost<0) continue;
        else answer=min(answer,cost);
    }
    
    
    // 플로이드 와샬
    int arr[MAX][MAX];
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i==j) arr[i][i]=0;
            else arr[i][j]=INF;
        }
    }
    
    for(int i=0; i<fares.size(); i++){
        arr[fares[i][0]][fares[i][1]]=fares[i][2];
        arr[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j]=min(arr[i][k]+arr[k][j],arr[i][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        answer=min(answer,arr[s][i]+arr[i][a]+arr[i][b]);
    }
    
    return answer;
}