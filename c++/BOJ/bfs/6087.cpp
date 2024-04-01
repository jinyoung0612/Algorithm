#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

int W,H;
char arr[MAX][MAX];
int visited[MAX][MAX][4];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct laser{
    int x;
    int y;
    int d;
};

vector< pair<int,int> > v;
int answer=987654321;

void bfs(){
    queue<laser> q;
    for(int i=0; i<4; i++){
        visited[v[0].first][v[0].second][i]=0;
        laser ll={v[0].first,v[0].second,i};
        q.push(ll);
    }

    while(!q.empty()){
        
        laser cur=q.front();
        q.pop();

        if(cur.x==v[1].first&&cur.y==v[1].second){
               answer=min(answer,visited[cur.x][cur.y][cur.d]);
        }

        for(int i=0; i<4; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(0<=nx&&nx<H&&0<=ny&&ny<W&&arr[nx][ny]!='*'){
                
                if(i!=cur.d && visited[nx][ny][i]>visited[cur.x][cur.y][cur.d]+1){
                    visited[nx][ny][i]=visited[cur.x][cur.y][cur.d]+1;
                    laser tmp1={nx,ny,i};
                    q.push(tmp1);

                }
                else if(i==cur.d && visited[nx][ny][i]>visited[cur.x][cur.y][cur.d]){
                    visited[nx][ny][i]=visited[cur.x][cur.y][cur.d];
                    laser tmp2={nx,ny,i};
                    q.push(tmp2);
                }
                
            }
        }
    }
   
}
int main(void){
    
    cin>>W>>H;
    
    string str;
    for(int i=0; i<H; i++){
        cin>>str;
        for(int j=0; j<str.size(); j++){
            arr[i][j]=str[j];
            
            if(arr[i][j]=='C'){
                v.push_back(make_pair(i,j));
            }
            
            for(int k=0; k<4; k++){
                visited[i][j][k]=987654321;
            }
        }
        
    }

    bfs();
    
    cout<<answer;
    
    return 0;
}