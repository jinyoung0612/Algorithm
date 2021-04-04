#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 101
int R,C,M;

struct shark{
    int s,d,z;
};
shark arr[MAX][MAX];
shark tmp[MAX][MAX];
shark zero={0,0,0};

int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};

int answer=0;

void catchShark(int idx){
    
    for(int i=1; i<=R; i++){
        if(arr[i][idx].z){
            answer+=arr[i][idx].z;
            arr[i][idx]=zero;
            break;
        }
    }
}

void moveShark(int r, int c, shark S){
    int dir=S.d;
    int x=r;
    int y=c;
    int speed=S.s;
    
    // 시간초과 해결한 부분
    if(dir==1 || dir==2){

        int rotate=(R-1)*2;
        if(speed>=rotate) speed%=rotate;
    }
    else{
        int rotate=(C-1)*2;
        if(speed>=rotate) speed%=rotate;
    }
        
    for(int i=0; i<speed; i++){
        
        x+=dx[dir];
        y+=dy[dir];
        
        if(x<=0 || x>R || y<=0 || y>C){
            switch(dir){
                case(1): dir=2; x+=1; break;
                case(2): dir=1; x-=1; break;
                case(3): dir=4; y-=1; break;
                case(4): dir=3; y+=1; break;
            }
            
            x+=dx[dir];
            y+=dy[dir];
        }

    }

    if(tmp[x][y].z==0){
        shark s1={S.s,dir,S.z};
        tmp[x][y]=s1;
    }
    else{
        if(tmp[x][y].z<S.z){
            shark s2={S.s,dir,S.z};
            tmp[x][y]=s2;
        }
    }

}

void moveAll(){
    memset(tmp,0,sizeof(tmp));

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(arr[i][j].z){
                moveShark(i, j, arr[i][j]);
            }
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            arr[i][j]=tmp[i][j];
        }
    }
}

int main(void){
    
    cin>>R>>C>>M;
    
    int r,c,s,d,z;
    
    for(int i=0; i<M; i++){
        cin>>r>>c>>s>>d>>z;
        shark sh={s,d,z};
        arr[r][c]=sh;
    }

    if(M>0){
        for(int i=1; i<=C; i++){
            catchShark(i);
            moveAll();
        }
    }


    cout<<answer;
   
   
    return 0;
}