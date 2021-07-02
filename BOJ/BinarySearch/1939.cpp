
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001
vector<pair<int,int>>graph[MAX];
bool visited[MAX];
int start;
int End;

bool bfs(int cost){
    queue<int> q;
    q.push(start);
    visited[start]=1;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        if(cur==End){
            return true;
        }

        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i].first;
            int ncost=graph[cur][i].second;

            if(!visited[next]&&cost<=ncost){
                visited[next]=1;
                q.push(next);
            }
        }

    }
    return false;
}
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N,M;
    cin>>N>>M;
    int A,B,C;
    int answer=0;
    int max_cost=0;
    for(int i=0; i<M; i++){
        cin>>A>>B>>C;
        graph[A].push_back({B,C});
        graph[B].push_back({A,C});
        max_cost=max(max_cost,C);
    }
    cin>>start>>End;

    int left=0;
    int right=max_cost;

    while(left<=right){
        int mid=(left+right)/2;
        memset(visited,false, sizeof(visited));

        if(bfs(mid)){
            answer=max(answer,mid);
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<answer;
    return 0;

}
