#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001

vector<vector<int> > graph;
int parent[MAX];

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
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
    int N,M;

    cin>>N>>M;
    int a,b,c;
    for(int i=0; i<M; i++){
        cin>>a>>b>>c;
        vector<int> temp;
        temp.push_back(c);
        temp.push_back(a);
        temp.push_back(b);
        graph.push_back(temp);

    }

    sort(graph.begin(),graph.end());

    for(int i=1; i<=N; i++){
        parent[i]=i;
    }
    
    int answer=0;
    for(int i=0; i<M; i++){
        if(getParent(graph[i][1])!=getParent(graph[i][2])){
            unionParent(graph[i][1],graph[i][2]);
            answer+=graph[i][0];
        }
    }
    cout<<answer;

    return 0;
} 