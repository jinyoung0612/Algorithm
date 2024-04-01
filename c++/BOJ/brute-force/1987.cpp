#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 21

int R,C;
char arr[MAX][MAX];
bool check[26];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int max_val=0;
void dfs(int x, int y,int cnt){
   
    max_val=max(cnt,max_val);

    for(int i=0; i<4; i++){

        int nx=x+dx[i];
        int ny=y+dy[i];

        if(1<=nx&&nx<=R&&1<=ny&&ny<=C){
            if(!check[arr[nx][ny]-'A']){
                check[arr[nx][ny]-'A']=1;
                dfs(nx,ny,cnt+1);
                check[arr[nx][ny]-'A']=0;
            }
            
        }
    }
}
int main(void){

  
    cin>>R>>C;
    string str;
    for(int i=1; i<=R; i++){
        cin>>str;
        for(int j=1; j<=C; j++){
            arr[i][j]=str[j-1];
        }
    }
    check[arr[1][1]-'A']=1;
    dfs(1,1,1);
    cout<<max_val;

    return 0;
}