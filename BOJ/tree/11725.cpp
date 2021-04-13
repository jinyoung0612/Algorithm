#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100001
int N;
vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX];

void getParent(int x){
    visited[x]=1;

    for(int i=0; i<tree[x].size(); i++){
        int next=tree[x][i];

        if(!visited[next]){
            parent[next]=x;
            getParent(next);
        }
    }
}

int main(void){
    cin>>N;
    int a,b;
    
    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    getParent(1);

    for(int i=2; i<=N; i++){
        cout<<parent[i]<<"\n";
    }

    return 0;
}