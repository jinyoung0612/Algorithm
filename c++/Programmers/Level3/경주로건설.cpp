#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 26

int visited[MAX][MAX];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

struct car{
    int x;
    int y;
    int dir;
    int cost;
};

int solution(vector<vector<int> > board) {
    int answer = 987654321;
    
    int N=board.size();
    int M=board[0].size();
    
    queue<car> q;
    car c={0,0,-1,0};
    q.push(c);
    visited[0][0]=1;
    
    while(!q.empty()){
        car cur=q.front();
        q.pop();
    
        if(cur.x==N-1&&cur.y==M-1){
            answer=min(answer, cur.cost);
        }
        
        for(int i=0; i<4; i++){
            
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            
            if(nx<0 || nx>=N || ny<0 || ny>=M || board[nx][ny]!=0) continue;
    
            
            int ncost=0;
            if(cur.dir!=-1&&cur.dir!=i){
                ncost=600+cur.cost;
            }
            else ncost=100+cur.cost;
            
            if(!visited[nx][ny] || visited[nx][ny]>=ncost){
                visited[nx][ny]=ncost;
                car temp={nx,ny,i,ncost};
                q.push(temp);
            }


        }
    }
    return answer;
}