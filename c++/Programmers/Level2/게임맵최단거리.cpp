#include <vector>
#include <queue>
using namespace std;

#define MAX 101
int visited[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int solution(vector<vector<int> > maps)
{
    int answer = -1;
   
    int N=maps.size();
    int M=maps[0].size();
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visited[0][0]=1;
    
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        if(cx==N-1&&cy==M-1){
            answer=visited[cx][cy];
            break;
        }
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            
            if(maps[nx][ny]==1&&!visited[nx][ny]){
                visited[nx][ny]=visited[cx][cy]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }

    return answer;
}