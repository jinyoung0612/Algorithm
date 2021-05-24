#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 251

int R,C;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sheep;
int wolf;

void dfs(int x, int y){

    visited[x][y]=1;
    
    if(arr[x][y]=='v'){
        wolf++;
    }
    else if(arr[x][y]=='k'){
        sheep++;
    }

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0 || nx>=R || ny<0 || ny>=C || arr[nx][ny]=='#') continue;
        
        if(!visited[nx][ny]){      
            dfs(nx,ny);
        }
        
    }
    
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>R>>C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
        }
    }

    int v=0;
    int k=0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j]!='#'&&!visited[i][j]){
                sheep=0;
                wolf=0;

                dfs(i,j);

                if(wolf<sheep) wolf=0;
                else sheep=0;

                v+=wolf;
                k+=sheep;
            }
        }
    }
    cout<<k<<" "<<v;
    return 0;
} 