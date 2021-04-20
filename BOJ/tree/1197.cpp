#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001
int parent[MAX];
bool visited[MAX];
int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
}
void UnionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int V,E;
    cin>>V>>E;
    
    vector<vector<int> > v;
    
    int a,b,c;
    // 1. Kruskal Algorithm
    // for(int i=0; i<E; i++){
    //     cin>>a>>b>>c;
    //     vector<int> temp;
        
    //     temp.push_back(c);
    //     temp.push_back(a);
    //     temp.push_back(b);
    //     v.push_back(temp);
    // }

    // sort(v.begin(),v.end());
    
    // int answer=0;
    
    // for(int i=1; i<=V; i++){
    //     parent[i]=i;
    // }

    // for(int i=0; i<E; i++){
    //     if(getParent(v[i][1])!=getParent(v[i][2])){
    //         answer+=v[i][0];
    //         UnionParent(v[i][1],v[i][2]);      
    //     }
    // }

    // cout<<answer;

    // 2. Prim's Algorithm

    vector< pair<int, int> > graph[MAX];
    
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(c,b));
        graph[b].push_back(make_pair(c,a));
    }

    int answer=0;
    
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0,1));
    
    while(!pq.empty()){
        pair<int,int> cur=pq.top();
        pq.pop();

        if(!visited[cur.second]){
            visited[cur.second]=1;
            answer+=cur.first;
        }

        for(int i=0; i<graph[cur.second].size(); i++){
            int next=graph[cur.second][i].second;
            int ncost=graph[cur.second][i].first;
            if(!visited[next]){
                pq.push(make_pair(ncost,next));
            }

        }
    }
    cout<<answer;
    

    return 0;
}