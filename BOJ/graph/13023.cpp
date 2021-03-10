#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 2001
vector<int> friends[MAX];
bool visited[MAX]={0,};
bool flag=false;
void dfs(int a,int idx){
    visited[a]=1;
    
    if(idx==4){
        cout<<1;
        flag=true;
        return;
    }

    for(int i=0; i<friends[a].size(); i++){
        if(!visited[friends[a][i]]){
            if(flag) return;
            dfs(friends[a][i],idx+1);
        }
    }
    visited[a]=0;
}
int main(void){
    int N,M;
    cin>>N>>M;
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i=0; i<N; i++){
        dfs(i,0);
    }
    if(!flag) cout<<0;
    
    return 0;
}