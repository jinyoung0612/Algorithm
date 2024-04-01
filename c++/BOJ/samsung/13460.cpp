#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 11

int N,M;
char map[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[MAX][MAX][MAX][MAX]={0,};

struct balls {
    int cnt;
    int rx;
    int ry;
    int bx;
    int by;
};

void BFS(int rx, int ry, int bx, int by){
    bool flag=false;
    queue<balls> q;
    balls b={0,rx,ry,bx,by};
    q.push(b);
    visited[rx][ry][bx][by]=1;

    while(!q.empty()){
    
       balls cur=q.front();
       q.pop();
        
        if(cur.cnt>10){
           cout<<-1;
           return;
       }

       if(map[cur.rx][cur.ry]=='O'){
           flag=true;
           cout<<cur.cnt;
           return;
       }
       for(int i=0; i<4; i++){
           int nrx=cur.rx;
           int nry=cur.ry;
           int nbx=cur.bx;
           int nby=cur.by;

           while(1){
               nrx+=dx[i];
               nry+=dy[i];
               if(map[nrx][nry]=='#'){
                   nrx-=dx[i];
                   nry-=dy[i];
                   break;
               }
               else if(map[nrx][nry]=='O'){
                   break;
               }
           }

            while(1){
                nbx+=dx[i];
                nby+=dy[i];
               if(map[nbx][nby]=='#'){
                   nbx-=dx[i];
                   nby-=dy[i];
                   break;
               }
               else if(map[nbx][nby]=='O'){
                   break;
               }
           }

           if(map[nbx][nby]=='O') continue;
           

           if(nrx==nbx && nry==nby){
               switch(i){
                   case 0: cur.rx<cur.bx ? nrx-- : nbx--; break;
                   case 1: cur.rx<cur.bx ? nbx++ : nrx++; break;
                   case 2: cur.ry<cur.by ? nry-- : nby--; break;
                   case 3: cur.ry<cur.by ? nby++ : nry++; break;
               }

           }

           if(!visited[nrx][nry][nbx][nby]){
               balls temp={cur.cnt+1,nrx,nry,nbx,nby};
               q.push(temp);
               visited[nrx][nry][nbx][nby]=1;
           } 
       }
    }
    if(!flag){
        cout<<-1;
        return;
    }
   
}

int main(void){
   
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>map[i];
    }
      
    int rx,ry,bx,by;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]=='R'){
                rx=i;
                ry=j;
                map[i][j]='.';
            }
            else if(map[i][j]=='B'){
                bx=i;
                by=j;
                map[i][j]='.';
            }
        }
    }

    BFS(rx,ry,bx,by);

    return 0;
}

