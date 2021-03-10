#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

#define MAX 1001
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX]={0,};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct miro{
    int x, y, times;
};

int bfs(){
    deque<miro> dq;
    miro temp={0,0,0};
    visited[0][0]=1;

    dq.push_back(temp);

    while(!dq.empty()){
        int x=dq.front().x;
        int y=dq.front().y;
        int times=dq.front().times;
        
        dq.pop_front();

        if(x==m-1&&y==n-1) return times;

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0<=nx&&nx<m&&0<=ny&&ny<n){
                if(arr[nx][ny]==0&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    miro temp2={nx,ny,times};
                    dq.push_front(temp2);
                }

                if(arr[nx][ny]==1&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    miro temp3={nx,ny,times+1};
                    dq.push_back(temp3);
                }
            }
        }
    }
    return 0;
}
int main(void){
    cin>>n>>m;
    string str;
    for(int i=0; i<m; i++){
        cin>>str;
        for(int j=0; j<n; j++){
            arr[i][j]=str[j]-'0';
        }
    }
    cout<<bfs();
    return 0;
}