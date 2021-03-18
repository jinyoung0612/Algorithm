#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 101

int arr[MAX][MAX]={0,};

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

void dragon_curve(int x, int y, int d, int g){
    vector<int> dir;

    arr[y][x]=1;
    dir.push_back(d);

    for(int i=1; i<=g; i++){
        int dsize=dir.size();
        for(int j=dsize-1; j>=0; j--){
            dir.push_back((dir[j]+1)%4);
        }

    }

    for(int i=0; i<dir.size(); i++){
        int ny=y+dy[dir[i]];
        int nx=x+dx[dir[i]];
        arr[ny][nx]=1;
        y=ny;
        x=nx;
    }

}
int main(void){
    int n;
    cin>>n;
    int x,y,d,g;
    int answer=0;
    for(int i=0; i<n; i++){
        cin>>x>>y>>d>>g;
        dragon_curve(x,y,d,g);
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
           if(arr[i][j]==1&&arr[i+1][j]==1&&arr[i][j+1]==1&&arr[i+1][j+1]==1){
               answer++;
           }
        }
    }
    cout<<answer;

  

    return 0;
}