#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define MAX 101
int arr[MAX][MAX][MAX];

int M,N,H;

int dx[6]={0,0,0,0,1,-1};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={1,-1,0,0,0,0};

struct tomato{
    int x;
    int y;
    int z;
    int day;
};

bool check(){

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(arr[j][k][i]==0){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(void){
   
    
    cin>>M>>N>>H;
    queue<tomato> q;
    int answer=0;

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin>>arr[j][k][i];
                if(arr[j][k][i]==1){
                    tomato t={j,k,i,0};
                    q.push(t);
                }
            }
        }
    }

   while(!q.empty()){
        tomato cur=q.front();
        q.pop();

        answer=max(answer,cur.day);
        for(int i=0; i<6; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            int nz=cur.z+dz[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H || arr[nx][ny][nz]!=0) continue;

            arr[nx][ny][nz]=1;
            tomato tmp={nx,ny,nz,cur.day+1};
            q.push(tmp);
        } 
    }

   if(check()){
       cout<<answer;
   }
   else{
       cout<<-1;
   }


    return 0;
}