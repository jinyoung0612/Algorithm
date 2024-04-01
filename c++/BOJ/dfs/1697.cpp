#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001

int N,K;
int visited[MAX]={0,};
int map[MAX]={0,};
queue<int> q;

void BFS(int n, int k){
   
    q.push(n);
    visited[n]=1;

    while(!q.empty()){
        int p=q.front();
        q.pop();

        if(p==k) return;

       if(p-1>=0&&!visited[p-1]){
            q.push(p-1);
            visited[p-1]=1;
            map[p-1]=map[p]+1;
        }
        if(p+1<=100000&&!visited[p+1]){
            q.push(p+1);
            visited[p+1]=1;
            map[p+1]=map[p]+1;
        }
        if(p*2<=100000&&!visited[p*2]){
            q.push(2*p);
            visited[2*p]=1;
            map[2*p]=map[p]+1;
        }
    }

}

int main(void){
    
    cin>>N>>K;
    BFS(N,K);
    cout<<map[K]<<endl;
    return 0;
}