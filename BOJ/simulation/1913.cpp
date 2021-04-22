#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000

int arr[MAX][MAX];

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    int num=N*N;
    int x=1;
    int y=1;
    int dir=0;
    int fx=0;
    int fy=0;
    for(int i=1; i<=N; i++){
       if(dir==0){
           for(int j=i; j<=N; j++){
               if(num==M){
                   fx=x;
                   fy=y;
               }
               arr[x++][y]=num--;
           }
           x--;
           y++;
           dir=1;
           continue;
       }
       else if(dir==1){
           for(int j=i; j<=N; j++){
               if(num==M){
                   fx=x;
                   fy=y;
               }
               arr[x][y++]=num--;
           }
           x--;
           y--;
           dir=2;
           i--;
           continue;
       }
       else if(dir==2){
           for(int j=i; j<=N; j++){
               if(num==M){
                   fx=x;
                   fy=y;
               }
               arr[x--][y]=num--;
           }
           x++;
           y--;
           dir=3;
           continue;
       }
       else if(dir==3){
           for(int j=i; j<=N; j++){
                if(num==M){
                   fx=x;
                   fy=y;
               }
               arr[x][y--]=num--;
           }
           x++;
           y++;
           i--;
           dir=0;
           continue;
       }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<fx<<" "<<fy<<"\n";
    

   
    return 0;
} 