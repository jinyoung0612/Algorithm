#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
map <string,int> visited;

queue< pair<string,int> > q;
string target="123456780";
string start;

void bfs(){

    q.push(make_pair(start,0));
    visited[start]=1;
    int answer=0;

    while(!q.empty()){
        string cur=q.front().first;
        int cnt=q.front().second;
        q.pop();

        if(cur==target){
            answer=cnt;
            break;
        }

        int zero=cur.find('0');
        int x=zero/3;
        int y=zero%3;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0<=nx&&nx<3&&0<=ny&&ny<3){
                string next=cur;
                swap(next[x*3+y],next[nx*3+ny]);
                if(!visited[next]){
                    visited[next]=1;
                    q.push(make_pair(next,cnt+1));
                }
            }
        }
    }

    if(!visited[target]){
        cout<<-1;
    }
    else{
        cout<<answer;
    }

}

int main(void){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int num;
            cin>>num;
            start+=(num+'0'); 
        }
    }

    bfs();
   
    return 0;
}