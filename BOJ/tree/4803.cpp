#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 501

bool visited[MAX];
bool passed[MAX];
vector<int> tree[MAX];

int numOfVertex(int n){
    int cnt=1;
    visited[n]=1;

    for(int i=0; i<tree[n].size(); i++){
        int next=tree[n][i];
        if(!visited[next]){
            cnt+=numOfVertex(next);
        }
    }
    return cnt;
}
int numOfEdge(int n){
    int cnt=tree[n].size();
    passed[n]=1;

    for(int i=0; i<tree[n].size(); i++){
        int next=tree[n][i];
        if(!passed[next]){
            cnt+=numOfEdge(next);
        }
    }
    return cnt;
}
int main(void){
    int n,m;
    int cases=1;
    while(1){
        
        cin>>n>>m;
        if(n==0&&m==0) break;

        for(int i=0; i<MAX; i++){
            tree[i].clear();
        }
        memset(visited,false,sizeof(visited));
        memset(passed,false,sizeof(passed));

        int a,b;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int answer=0;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                int v=numOfVertex(i);
                int e=numOfEdge(i);

                if(v-1==(e/2)) answer++;
            }
        }
        cout<<"Case "<<cases++<<": ";
        if(answer==0){
            cout<<"No trees.\n";
        }
        else if(answer==1){
            cout<<"There is one tree.\n";
        }
        else{
            cout<<"A forest of "<<answer<<" trees.\n";
        }

    }
}