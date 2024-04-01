#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 51
int r,c;
char arr[MAX][MAX];
int visited[MAX][MAX]={0,};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue< pair<int, int> > river;
queue< pair<int, int> > q;

int bfs(){


    while(!q.empty()){
    
        int rSize=river.size();
        for(int i=0; i<rSize; i++){
            int wx=river.front().first;
            int wy=river.front().second;
            river.pop();

            for(int j=0; j<4; j++){
                int nwx=wx+dx[j];
                int nwy=wy+dy[j];

                if(0<=nwx&&nwx<r&&0<=nwy&&nwy<c){
                    if(arr[nwx][nwy]=='.'){
                        arr[nwx][nwy]='*';
                        river.push(make_pair(nwx,nwy));
                    }
                }
            }
        }

        int qSize=q.size();

        for(int i=0; i<qSize; i++){
            int cx=q.front().first;
            int cy=q.front().second;

            q.pop();

            if(arr[cx][cy]=='D') return visited[cx][cy]-1;

             for(int j=0; j<4; j++){
                int nx=cx+dx[j];
                int ny=cy+dy[j];

                if(0<=nx&&nx<r&&0<=ny&&ny<c){
                    if(!visited[nx][ny]){
                        if(arr[nx][ny]=='.' || arr[nx][ny]=='D'){
                            visited[nx][ny]=visited[cx][cy]+1;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }

            }

        }
    
        
      
    }
   
    return -1;

}
int main(void){
    cin>>r>>c;
    string str;
    for(int i=0; i<r; i++){
        cin>>str;
        for(int j=0; j<c; j++){
            arr[i][j]=str[j];
            if(arr[i][j]=='*'){
                river.push(make_pair(i,j));
            }
            else if(arr[i][j]=='S'){
                q.push(make_pair(i,j));
                visited[i][j]=1;
            }
        }
    }

    int result=bfs();

    if(result==-1) cout<<"KAKTUS";
    else cout<< result;

    return 0;
}