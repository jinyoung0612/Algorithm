#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

#define MAX 100001
int N,K;
bool visited[MAX];
int answer=0; 
int fast_time=0;

void bfs(){
    queue< pair<int, int> > q;
    visited[N]=1;
    q.push(make_pair(N,0));

    while(!q.empty()){
        int pos=q.front().first;
        int time=q.front().second;
            
        q.pop();
        visited[pos]=1;

        if(fast_time!=0&&fast_time==time&&pos==K){
            answer++;
        }
        if(fast_time==0&&pos==K){
            fast_time=time;
            answer++;
        }
        
        int next=pos+1;
        if(next<=100000&&!visited[next]){
            q.push(make_pair(next,time+1));
        }

        next=pos-1;
         if(0<=next&&!visited[next]){
            q.push(make_pair(next,time+1));
        }

        next=pos*2;
        if(next<=100000&&!visited[next]){
            q.push(make_pair(next,time+1));
        
        }

    }

    return;
}

int main(void){

    cin>>N>>K;
    bfs();
    cout<<fast_time<<"\n"<<answer;
    
    return 0;
}