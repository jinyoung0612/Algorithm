#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 301

int arr[MAX][MAX];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M,R;
    cin>>N>>M>>R;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    
    int group=min(N,M)/2;

    while(R--){
        for(int j=0; j<group; j++){
            
            int y=j;
            int x=j;
            int value=arr[y][x];
            int dir=0;

            while(dir<4){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                if(ny>=j&&ny<N-j&&nx>=j&&nx<M-j){
                    arr[y][x]=arr[ny][nx];
                    y=ny;
                    x=nx;
                }
                else{
                    dir+=1;
                }
            }
            arr[j+1][j]=value;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
} 