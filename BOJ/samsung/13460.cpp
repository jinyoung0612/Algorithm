#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 11
int N,M;
char map[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[MAX][MAX]={0,};
int answer=0;
bool success=0;

void DFS(int rx, int ry, int bx, int by, int count){
    if(count==10) return;
    if(success) return;

    if(map[x][y]=='O'){
        if(count>10) answer=-1;
        answer=count;
        return;
    }

    
    for(int i=0; i<4; i++){
        int nrx=rx+dx[i];
        int nry=ry+dy[i];
        int nbx=bx+dx[i];
        int nby=by+dy[i];

        if(0<=next_x&&next_x<N&0<=next_y&&next_y<M){
            if(map[next_x][next_y]=='.'&&!visited[next_x][next_y]){
                visited[next_x][next_y]=1;
                DFS(next_x,next_y,count+1);
                
            }
        }
    }

}
int main(void){
   
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>map[i];
    }

    int rx,ry,bx,by;
    
    for(int i=0; i<N; i++){
        for(int j=0; i<M; j++){
            if(map[i][j]=='R'){
                rx=i,ry=j;
                map[i][j]='.';
            }
            else if(map[i][j]='B'){
                bx=i, by=j;
                map[i][j]='.';
            }
        }
    }
    DFS(rx,ry,bx,by,0);
    cout<<answer;

    return 0;
}