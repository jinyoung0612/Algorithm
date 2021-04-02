#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define MAX 51
int R,C,T;
int arr[MAX][MAX];
int dx[4]={1,-1,0,0}; // S N E W
int dy[4]={0,0,1,-1};

int ccw[4]={2,1,3,0};
int cw[4]={2,0,3,1};
vector< pair< pair<int,int>, int > > v;
vector<int> cleaner;

void diffusion(){

    v.clear();
    for(int i=0; i<R; i++){
       for(int j=0; j<C; j++){

           if(arr[i][j]>0){
               int cnt=0;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];

                    if(0<=nx&&nx<R&&0<=ny&&ny<C&&arr[nx][ny]!=-1){
                        v.push_back(make_pair(make_pair(nx,ny),arr[i][j]/5));
                        cnt++;
                    }
                }
               
               if(cnt>0){
                   arr[i][j]-=(cnt*(arr[i][j]/5));
               }
           }
       }
   }

   for(int i=0; i<v.size(); i++){
       arr[v[i].first.first][v[i].first.second]+=v[i].second;
   }

}

void run1(){
    queue<int> q;

   int row=cleaner[0];

    for(int i=row-1; i>=0; i--){
        q.push(arr[i][0]);
    }

    for(int i=1; i<C; i++){
        q.push(arr[0][i]);
    }

    for(int i=1; i<=row; i++){
        q.push(arr[i][C-1]);
    }
    for(int i=C-2; i>=1; i--){
        q.push(arr[row][i]);
    }
   
    q.pop(); //첫번째 원소 제거

    for(int i=row-1; i>=0; i--){
        arr[i][0]=q.front();
        q.pop();
    }

    for(int i=1; i<C; i++){
        arr[0][i]=q.front();
        q.pop();
    }

    for(int i=1; i<=row; i++){
        arr[i][C-1]=q.front();
        q.pop();
    }
    for(int i=C-2; i>=2; i--){
        arr[row][i]=q.front();
        q.pop();
    }
    arr[row][1]=0;

}

void run2(){

    queue<int> q;

   int row=cleaner[1];

   for(int i=row+1; i<R; i++){
       q.push(arr[i][0]);
   }
   for(int i=1; i<C; i++){
       q.push(arr[R-1][i]);
   }
   for(int i=R-2; i>=row; i--){
       q.push(arr[i][C-1]);
   }
   for(int i=C-2;i>=1; i--){
       q.push(arr[row][i]);
   }

   q.pop();

   for(int i=row+1; i<R; i++){
       arr[i][0]=q.front();
       q.pop();
   }
   for(int i=1; i<C; i++){
       arr[R-1][i]=q.front();
       q.pop();
   }
   for(int i=R-2; i>=row; i--){
       arr[i][C-1]=q.front();
       q.pop();
   }
   for(int i=C-2; i>=2; i--){
       arr[row][i]=q.front();
       q.pop();
   }

   arr[row][1]=0;
}


void counterclock(){

    int temp[MAX][MAX];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            temp[i][j]=arr[i][j];
        }
    }

    int row=cleaner[0];
    int col=1;

    arr[row][col]=0;

    for(int i=0; i<4; i++){
        
        while(1){
            int nx=row+dx[ccw[i]];
            int ny=col+dy[ccw[i]];

            if(nx==cleaner[0]&&ny==0) break;
            if(nx<0 || nx>=R || ny<0 || ny>=C) break;

            arr[nx][ny]=temp[row][col];
            row=nx;
            col=ny;

        }
    }

}
void clockwise(){
    int temp[MAX][MAX];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            temp[i][j]=arr[i][j];
        }
    }

    int row=cleaner[1];
    int col=1;

    arr[row][col]=0;

    for(int i=0; i<4; i++){
        
        while(1){
            int nx=row+dx[cw[i]];
            int ny=col+dy[cw[i]];

            if(nx==cleaner[1]&&ny==0) break;
            if(nx<0 || nx>=R || ny<0 || ny>=C) break;

            arr[nx][ny]=temp[row][col];
            row=nx;
            col=ny;

        }
    }
}

int main(void){
    
   
   cin>>R>>C>>T;

   for(int i=0; i<R; i++){
       for(int j=0; j<C; j++){
           cin>>arr[i][j];
           if(arr[i][j]==-1){
               cleaner.push_back(i);
           }
       }
   }

   for(int i=0; i<T; i++){
       diffusion();
    //    run1();
    //    run2();
        counterclock();
        clockwise();
   }

    int answer=0;
    for(int i=0; i<R; i++){
       for(int j=0; j<C; j++){
           if(arr[i][j]>0){
               answer+=arr[i][j];
           }
       }
   }
   cout<<answer;

    return 0;
}