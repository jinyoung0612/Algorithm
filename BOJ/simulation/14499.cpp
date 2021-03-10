#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[20][20];
int dice[7];

int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};

void rollDice(int dir){
    int d1=dice[1];
    int d2=dice[2];
    int d3=dice[3];
    int d4=dice[4];
    int d5=dice[5];
    int d6=dice[6];

    if(dir==1){
        dice[1]=d4;
        dice[4]=d6;
        dice[6]=d3;
        dice[3]=d1;
    }
    else if(dir==2){
        dice[1]=d3;
        dice[4]=d1;
        dice[6]=d4;
        dice[3]=d6;
    }
    else if(dir==3){
        dice[1]=d5;
        dice[5]=d6;
        dice[6]=d2;
        dice[2]=d1;
    }
    else if(dir==4){
        dice[1]=d2;
        dice[5]=d1;
        dice[6]=d5;
        dice[2]=d6;
    }
}
int main(void){
    int n,m;
    int start_x,start_y;
    int inst_num;

    cin>>n>>m>>start_x>>start_y>>inst_num;
    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }

    int dir;
    int bottom=6;
    for(int i=0; i<inst_num; i++){
        
        cin>>dir;
        int nx=start_x+dx[dir];
        int ny=start_y+dy[dir];

        if(0<=nx&&nx<n&&0<=ny&&ny<m){
            rollDice(dir);
            if(map[nx][ny]==0) map[nx][ny]=dice[6];
            else{
                dice[6]=map[nx][ny];
                map[nx][ny]=0;
            }
            cout<<dice[1]<<"\n";
            start_x=nx;
            start_y=ny;

        }
    }



   
    return 0;
}