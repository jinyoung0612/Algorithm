#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 300001

int N,M,K,X;
vector<int> edge[MAX];
int visited[MAX];

void bfs(){
    queue<int> q;
    q.push(X);
    visited[X]=1;

    while(!q.empty()){
        int city=q.front();
        q.pop();

        for(int i=0; i<edge[city].size(); i++){
            int next=edge[city][i];
            if(!visited[next]){
                visited[next]=visited[city]+1;  
                q.push(next);
            }
        }
    }


}
int main(void){
   cin>>N>>M>>K>>X;
   int x, y;

   for(int i=0; i<M; i++){
       cin>>x>>y;
       edge[x].push_back(y);
   }

   bfs();

    vector<int> answer;
    for(int i=1; i<=N; i++){
       if(visited[i]-1==K) answer.push_back(i);
    }

    if(answer.size()==0){
        cout<<-1;
    }
    else{
        sort(answer.begin(),answer.end());
        for(int i=0; i<answer.size(); i++){
            cout<<answer[i]<<"\n";
        }
    }
   
    return 0;
}