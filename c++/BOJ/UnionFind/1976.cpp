#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 201
int cities[MAX][MAX];
int plan[1001];
bool visited[MAX];
int parent[MAX];

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

    int N,M;
    cin>>N>>M;

    // 1. BFS 2180KB 4ms

    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cin>>cities[i][j];

    //     }
    // }
    // for(int i=0; i<M; i++){
    //     cin>>plan[i];
    // }
    

    // queue<int> q;
    // q.push(plan[0]);
    // while(!q.empty()){
    //     int cur=q.front();
    //     visited[cur]=1;
    //     q.pop();

    //     for(int i=1; i<=N; i++){
    //         if(!visited[i]&&cities[cur][i]){
    //             q.push(i);
    //         }
    //     }

    // }

    // bool flag=true;
    // for(int i=0; i<M; i++){
    //    if(!visited[plan[i]]){
    //        flag=false;
    //        break;
    //    }
    // }
   
    // 2. Union-Find 2016KB 0ms
    for(int i=1; i<=N; i++) parent[i]=i;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int conn;
            cin>>conn;
            if(conn){
                if(getParent(i)!=getParent(j)){
                    UnionParent(i,j);
                }
            }
        }
    }
    int root,city;
    bool flag=true;
    for(int i=0; i<M; i++){
        cin>>city;
        if(i==0){
            root=getParent(city);
        }
        else{
            if(root!=getParent(city)){
                flag=false;
                break;
            }
        }
    }

     if(flag==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}