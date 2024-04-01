#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1001

vector<int> graph[MAX];
int inDeg[MAX];
int result[MAX];
queue<int> q;

int main(void){
    int N,M;
    cin>>N>>M;
    int a,b;
    
    for(int i=0 ;i<M; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        inDeg[b]+=1;
    }

    for(int i=1; i<=N; i++){
        if(inDeg[i]==0){
            q.push(i);
        }
        result[i]=1;
    }

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i];
            inDeg[next]-=1;
            if(inDeg[next]==0){
                q.push(next);
                result[next]=max(result[next],result[cur]+1);
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout<<result[i]<<" ";
    }

    return 0;
}