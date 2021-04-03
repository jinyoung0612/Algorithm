#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define MAX 31

int N,M,H;
int arr[11][31];
bool visited[11][31];
int answer=987654321;

void dfs(int cnt, int idx){
    
    if(cnt>3) return;
   
    bool flag=true;

    for(int i=1; i<=N; i++){
        int num=i;
        for(int j=1; j<=H; j++){
            if(visited[num][j]==1) num+=1;
            else if(visited[num-1][j]==1) num-=1;
        }
        if(num!=i){
            flag=false;
            break;
        }
    }

    if(flag){
        answer=min(answer,cnt);
        return;
    }

    for(int i=idx; i<=H; i++){
        for(int j=1; j<N; j++){
            if(visited[j][i]==1) continue;
            if(visited[j-1][i]==1) continue;
            if(visited[j+1][i]==1) continue;
            
            visited[j][i]=1;
            dfs(cnt+1,i);
            visited[j][i]=0;
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>H;
    
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        visited[b][a]=1;
    }
    dfs(0,1);

    if(answer==987654321){
        cout<<-1;
    }
    else{
        cout<<answer;
    }
    return 0;
}