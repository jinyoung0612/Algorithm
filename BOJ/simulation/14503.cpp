#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 51

 int n,m;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int answer=1;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int by[4]={1,0,-1,0};
int bx[4]={0,-1,0,1};

int cnt;
void dfs(int y, int x,int d){
    if(arr[y][x]==0&&!visited[y][x]){
        cnt++;
        visited[y][x]=1;
    }

   for(int k=d-1; k>d-5; k--){
       int nk=(k+4)%4;
       int ny=y+dy[nk];
       int nx=x+dx[nk];
       if(0<=nx&&nx<m&&0<=ny&&ny<n){
           if(arr[ny][nx]==0&&!visited[ny][nx]){
               dfs(ny,nx,nk);
               return;
           }
       }
   }

   if(arr[y+by[d]][x+bx[d]]==1) return;
   else dfs(y+by[d],x+bx[d],d);

}

int main(void){

   
    cin>>n>>m;
    int rr, rc, d;
    cin>>rr>>rc>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    dfs(rr,rc,d);
    cout<<cnt;


    return 0;
}