#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 101

bool visited[MAX];
int graph[MAX][MAX];
int main(void){
   
    int N;
    cin>>N;

    vector<int> network[N+1];
    int edge;
    cin>>edge;
    int a,b;
    
    for(int i=0; i<edge; i++){
        cin>>a>>b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1]=1;
    int cnt=0;
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0; i<network[cur].size(); i++){
            if(!visited[network[cur][i]]){
                q.push(network[cur][i]);
                visited[network[cur][i]]=1;
                cnt+=1;
            }
        }
    }
    cout<<cnt;

    

// 2. Floyd Warshall     
//     int cnt=0;
//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=N; j++){
//             graph[i][j]=10000;            
//         }
//     }
//     for(int i=0; i<edge; i++){
//         cin>>a>>b;
//         graph[a][b]=1;
//         graph[b][a]=1;
//     }


//     for(int k=1; k<=N; k++){
//         for(int i=1; i<=N; i++){
//             for(int j=1; j<=N; j++){
//                 if(graph[i][j]>graph[i][k]+graph[k][j]){
//                     graph[i][j]=graph[i][k]+graph[k][j];
//                 }
//             }
//         }
//     }
   

//    for(int i=2; i<=N; i++){
//        if(graph[1][i]!=10000){
//            cnt+=1;
//        }
//     }
//     cout<<cnt;
    return 0;
}