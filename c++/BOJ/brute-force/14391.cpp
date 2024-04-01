#include <iostream>
#include <cstring>
#include <string>

 
using namespace std;
#define MAX  4

int N,M;
int sheet[MAX][MAX];
bool visited[MAX][MAX];
int answer;

void check(){
    int sum=0;
    for(int i=0; i<N; i++){
        int rsum=0;
        for(int j=0; j<M; j++){
            if(visited[i][j]==1){
                rsum*=10;
                rsum+=sheet[i][j];
            }
            else{
                sum+=rsum;
                rsum=0;
            }
        }
        sum+=rsum;
    }

    for(int i=0; i<M; i++){
        int csum=0;
        for(int j=0; j<N; j++){
            if(visited[j][i]==0){
                csum*=10;
                csum+=sheet[j][i];
            }
            else{
                sum+=csum;
                csum=0;
            }
        }
        sum+=csum;
    }

    answer=max(answer,sum);

}
// void dfs(int x, int y){
   
//    if(x==N){
//        check();
//        return;

//    }
//    if(y==M){
//        dfs(x+1,0);
//        return;
//    }

//     //가로
//     visited[x][y]=1;
//     dfs(x,y+1);

//     //세로
//     visited[x][y]=0;
//     dfs(x,y+1);

// }

void dfs(int x, int y, int depth){
    if(depth>=N*M){
        check();
        return;
    }

    int nx=depth/M;
    int ny=depth%M;
    
    visited[nx][ny]=1;
    dfs(nx,ny,depth+1);

    visited[nx][ny]=0;
    dfs(nx,ny,depth+1);
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    string str;
    
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            sheet[i][j]=str[j]-'0';
        }
    }
  
    dfs(0,0,0);
    cout<<answer;
    return 0;
}