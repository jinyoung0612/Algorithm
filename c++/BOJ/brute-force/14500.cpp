#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 5001
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int sx[4][4]={{0,0,0,-1},{0,-1,-2,-1},{0,0,0,1},{0,1,0,-1}};
int sy[4][4]={{0,1,2,1},{0,0,0,1},{0,1,2,1},{0,1,1,1}};

int result=0;

void dfs(int x, int y, int len, int sum){
    

    if(len==4){
        result=max(result,sum);
        return;
    }

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(0<=nx&&nx<n&&0<=ny&&ny<m){
            if(!visited[nx][ny]){
                visited[nx][ny]=1;
                dfs(nx,ny,len+1,sum+arr[nx][ny]);
                visited[nx][ny]=0;
            }
        }
    }

}

void shape3(int x, int y){
    for(int i=0; i<4; i++){
        int temp=0;
        
        for(int j=0; j<4; j++){
            int nx=x+sx[i][j];
            int ny=y+sy[i][j];

            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                temp+=arr[nx][ny];
                result=max(result,temp);
            }
            else break;
        }
    }

}

int main(void){

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                visited[i][j]=1;
                dfs(i,j,1,arr[i][j]);
                visited[i][j]=0;
                shape3(i,j);
            }
        }
    }
    

    cout<<result;
    return 0;
}