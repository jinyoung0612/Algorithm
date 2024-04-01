#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 101

int N;
int graph[MAX][MAX];
// bool visited[MAX];
bool visited[MAX][MAX];

// 1. DFS
// void dfs(int num){
//     for(int i=0; i<N; i++){
//         if(graph[num][i]&&!visited[i]){
//             visited[i]=1;
//             dfs(i);
//         }
//     }
// }
int main(void){
  

    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>graph[i][j];
        }
    }

    // for(int i=0; i<N; i++){
    //     memset(visited,false,sizeof(visited));

    //     dfs(i);

    //     for(int j=0; j<N; j++){
    //         cout<<visited[j]<<" ";
    //     }
    //     cout<<"\n";
    // }
   
   // 2. Floyd Warshall
   for(int k=0; k<N; k++){
       for(int i=0; i<N; i++){
           for(int j=0; j<N; j++){
               if(graph[i][k]==1&&graph[k][j]==1){
                   graph[i][j]=1;
               }
           }
       }
   }
   for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}