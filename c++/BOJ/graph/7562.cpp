#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 301

int I;
int arr[MAX][MAX];
int visited[MAX][MAX];
int endy;
int endx;
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};

void bfs(int y, int x){
    queue< pair< pair<int, int> ,int> > q;
    q.push(make_pair(make_pair(y,x),0));
    visited[y][x]=1;

    while(!q.empty()){
        int cy=q.front().first.first;
        int cx=q.front().first.second;
        int times=q.front().second;
        q.pop();

        if(cy==endy&&cx==endx){
            cout<<times<<"\n";
            return;
        }

        for(int i=0; i<8; i++){
            int ny=cy+dy[i];
            int nx=cx+dx[i];
            if(nx<0 || nx>=I || ny<0 || ny>=I) continue;
            if(!visited[ny][nx]){
                visited[ny][nx]=1;
                q.push(make_pair(make_pair(ny,nx),times+1));
            }
        }

    }

}
int main(void){
   
   int t;
    int y;
    int x;
   cin>>t;
   for(int i=0; i<t; i++){
       cin>>I;
       cin>>y>>x;
       cin>>endy>>endx;
       bfs(y,x);
       memset(visited,false,sizeof(visited));
      
   }
    return 0;
}