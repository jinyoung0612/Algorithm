#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;

#define MAX 101
int board[MAX][MAX]; // 0: 비어 있는칸 1: 사과
bool visited[MAX][MAX]; //1: 뱀 있음 0: 뱀 없음
char direction[10001];
int n,k,l;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void solve(int y, int x){

    deque< pair<int, int> > dq;
    int time=0;
    dq.push_back(make_pair(y,x));
    visited[y][x]=1;
    int d=0;

    while(1){
        time++;

        int ny=y+dy[d];
        int nx=x+dx[d];

        if(nx<=0 || nx>n || ny<=0 || ny>n ||visited[ny][nx]==1){
            cout<<time;
            return;
        }

        if(board[ny][nx]==0){
            visited[ny][nx]=1;
            visited[dq.back().first][dq.back().second]=0;
            dq.pop_back();
            dq.push_front(make_pair(ny,nx));
        }
        else{
            board[ny][nx]=0;
            visited[ny][nx]=1;
            dq.push_front(make_pair(ny,nx));
        }
    
        if(direction[time]=='D'){
            switch(d){
                case(0):d=2; break;
                case(1):d=3; break;
                case(2):d=1; break;
                case(3):d=0; break;
            }
        }
        else if(direction[time]=='L'){
            switch(d){
                case(0):d=3; break;
                case(1):d=2; break;
                case(2):d=0; break;
                case(3):d=1; break;
            }
        }
        x=nx;
        y=ny;

    }

}
int main(void){
    
    cin>>n>>k;
    int y,x;
    for(int i=0; i<k; i++){
        cin>>y>>x;
        board[y][x]=1;
    }

    int t;
    char dir;
    cin>>l;
    for(int i=0; i<l; i++){
        cin>>t>>dir;
        direction[t]=dir;
    }
    solve(1,1);

    return 0;
}