#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 10000

int A,B;
bool visited[MAX];

void bfs(){

    queue< pair<int,string> > q;
    q.push(make_pair(A,""));

    while(!q.empty()){
        
        int num=q.front().first;
        string str=q.front().second;
        q.pop();

        if(num==B){
            cout<<str<<"\n";
            return;
        }

        int next=2*num%MAX;
        if(!visited[next]){
            visited[next]=1;
            q.push(make_pair(next,str+'D'));

        }
        next=(num-1)<0 ? 9999 : num-1;
        if(!visited[next]){
            visited[next]=1;
            q.push(make_pair(next,str+'S'));

        }
        next=(num%1000)*10+(num/1000);
         if(!visited[next]){
            visited[next]=1;
            q.push(make_pair(next,str+'L'));

        }
        
        next=(num/10)+(num%10)*1000;
         if(!visited[next]){
            visited[next]=1;
            q.push(make_pair(next,str+'R'));
        }

    }

    return;
}

int main(void){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>A>>B;
        bfs();
        memset(visited,0,sizeof(visited));
    }

    return 0;
}