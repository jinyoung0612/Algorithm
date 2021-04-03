#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 101

int N;
int graph[MAX][MAX];
bool visited[MAX];

void dfs(int num){
    for(int i=0; i<N; i++){
        if(graph[num][i]==1&&!visited[i]){
            visited[i]=1;
            dfs(i);
        }
    }
}
int main(void){
  

    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0; i<N; i++){
        memset(visited,false,sizeof(visited));

        dfs(i);

        for(int j=0; j<N; j++){
            cout<<visited[j]<<" ";
        }
        cout<<"\n";
    }
   
    return 0;
}