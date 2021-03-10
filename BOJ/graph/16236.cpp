#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 21
int n;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct fish{
    int x;
    int y;
    int dist;
};
struct cmp{
    bool operator()(fish a, fish b){
        if(a.dist==b.dist){
            if(a.x==b.x){
                return a.y>b.y;
            }
            return a.x>b.x;
        }
        return a.dist>b.dist;
    }
};

void bfs(int x, int y){
    queue<fish> q;
    fish f={x,y,0};
    q.push(f);
   int size=2;
   int state=0;
   int time=0;

   while(1){

       priority_queue<fish, vector<fish>, cmp> pq;

       while(!q.empty()){
           
           int cx=q.front().x;
           int cy=q.front().y;
           int cdist=q.front().dist;
           q.pop();
           
           for(int i=0; i<4; i++){
                int nx=cx+dx[i];
                int ny=cy+dy[i];

                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(arr[nx][ny]>size||visited[nx][ny]) continue;

                fish tmp={nx,ny,cdist+1};
                q.push(tmp);
                visited[nx][ny]=1;

                if(arr[nx][ny]<size&&arr[nx][ny]!=0){
                    pq.push(tmp);
                }

               
           }
       }

       memset(visited,0,sizeof(visited));

       if(!pq.empty()){
          
            fish cur=pq.top();
            pq.pop();
            arr[cur.x][cur.y]=0;
            state++;
            time=cur.dist;

            q.push(cur);
            visited[cur.x][cur.y]=1;
        
            if(state==size){
                size++;
                state=0;
            }
       }
       else{
           cout<<time;
           break;
       }

      
   }

}
int main(void){
    cin>>n;
    int sx, sy;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                sx=i;
                sy=j;
                arr[i][j]=0;
                visited[i][j]=1;
            }
        }
    }
    bfs(sx,sy);
    


    return 0;
}