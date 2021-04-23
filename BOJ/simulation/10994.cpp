#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 400

char arr[MAX][MAX];

void draw(int len, int startx, int starty){
    for(int i=0; i<len; i++){
        if(i==0 || i==len-1){
            for(int j=0; j<len; j++){
                arr[startx+i][starty+j]='*';
            }
        }
        else{
            arr[startx+i][starty]='*';
            arr[startx+i][starty+len-1]='*';

        }
    }
}

void square(int n, int startx, int starty){
    int len=4*n-3;;
    draw(len,startx,starty);
    if(n==1) return;
    square(n-1,startx+2,starty+2);
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<4*n-3; i++){
        for(int j=0; j<4*n-3; j++){
            arr[i][j]=' ';
        }
    }
    square(n,0,0);

    for(int i=0; i<4*n-3; i++){
        for(int j=0; j<4*n-3; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }


    return 0;
} 