#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

#define MAX 100001

int n,k;
int arr[MAX];
int parent[MAX];
bool visited[MAX];

void bfs(){
    queue< pair<int, int> >  q;
    
    q.push(make_pair(n,0));
    visited[n]=1;

    while(!q.empty()){
        
        int pos=q.front().first;
        int time=q.front().second;
        
        q.pop();

        if(pos==k){
            deque<int> dq;
            cout<<time<<"\n";
            dq.push_back(k);

            for(int i=pos; i!=n; i=parent[i]){
                dq.push_front(parent[i]);
            }

            while(!dq.empty()){
                cout<<dq.front()<<" ";
                dq.pop_front();
            }
           
        }

        if(0<=pos-1&&!visited[pos-1]){
            
            visited[pos-1]=1;
            parent[pos-1]=pos;
            q.push(make_pair(pos-1,time+1));
        }
        if(pos+1<=100000&&!visited[pos+1]){

            visited[pos+1]=1;
            parent[pos+1]=pos;
            q.push(make_pair(pos+1,time+1));


        }
        if(2*pos<=100000&&!visited[2*pos]){
            visited[2*pos]=1;
            parent[2*pos]=pos;
            q.push(make_pair(2*pos,time+1));

        }
    }
    return;

}


int main(void){

    cin>>n>>k;
    bfs();
    return 0;
}