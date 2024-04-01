#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001
int n,k;
int visited[MAX]={0,};

int bfs(){
    queue< pair<int, int> > q; //position, time
    q.push(make_pair(n,0));
    visited[n]=1;

    while(!q.empty()){
        int pos=q.front().first;
        int time=q.front().second;
        q.pop();

        if(pos==k) return time;

        if(2*pos<=100000&&!visited[2*pos]){
            visited[2*pos]=1;
            q.push(make_pair(2*pos,time));
        }
        if(0<=pos-1&&!visited[pos-1]){
            visited[pos-1]=1;
            q.push(make_pair(pos-1,time+1));
        }
        if(pos+1<=100000&&!visited[pos+1]){
            visited[pos+1]=1;
            q.push(make_pair(pos+1,time+1));

        }
  
    }
    return 0;
}
int main(void){
    cin>>n>>k;
    cout<<bfs();
    return 0;
}