#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 129
int paper[MAX][MAX];
int blue;
int white;
void find(int x, int y, int n){
    
    int color=paper[x][y];
    
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(paper[i][j]!=color){
                find(x,y,n/2);
                find(x+n/2,y,n/2);
                find(x,y+n/2,n/2);
                find(x+n/2,y+n/2,n/2);
                return;
            }
        }
    }
    
    if(color==1){
        blue+=1;
    }
    else{
        white+=1;
    }
  
    return;
   
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>paper[i][j];
        }
    }
    find(0,0,N);

    cout<<white<<"\n"<<blue;
 
    return 0;
}