#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath> 
#include <queue>
using namespace std;

#define MAX 101

float arr[MAX][2];
float parent[MAX];
bool visited[MAX];
vector<vector<float> >graph;
float getDist(float x1, float y1, float x2, float y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}
void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string a,b;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr[i][0]=stof(a);
        arr[i][1]=stof(b);
    }

    // 1. Kruskal: 4ms 간선의 개수가 작은 경우에 유리
    for(int i=0; i<n; i++){
        parent[i]=i;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            vector<float> temp;
            float dist=getDist(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
            temp.push_back(dist);
            temp.push_back(i);
            temp.push_back(j);
            graph.push_back(temp);
        }
    }
    sort(graph.begin(),graph.end());

    float answer=0;
    for(int i=0; i<graph.size(); i++){
        float dist=graph[i][0];
        int n1=(int)graph[i][1];
        int n2=(int)graph[i][2];

        if(getParent(n1)!=getParent(n2)){
            answer+=dist;
            unionParent(n1,n2);
        }

    }

    cout<<answer;

    // 2. Prim's Algorithm 0ms: 간선의 개수가 많은 경우 유리함
    priority_queue< pair<float,int>,vector<pair<float,int> >, greater<pair<float,int>>> pq;
    pq.push({0.0,0});
    float answer=0;
    int cnt=0;

    while(!pq.empty()){
        float dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        visited[node]=1;
        answer+=dist;
        cnt++;

        if(cnt==n){
            cout<<answer;
            break;
        }

        for(int i=0; i<n; i++){
            if(node==i || visited[i]) continue;
            pq.push({getDist(arr[node][0],arr[node][1],arr[i][0],arr[i][1]),i});
        }
    }



    
    return 0;
} 