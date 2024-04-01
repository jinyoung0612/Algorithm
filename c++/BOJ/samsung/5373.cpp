#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

//위 아래 앞 뒤 왼 오
char arr[6][3][3];
char tmp[6][3][3];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int cw[4]={3,1,2,0};
int ccw[4]={2,1,3,0};

void rotate(string str){
    char side=str[0];
    char dir=str[1];

    if(side=='U'){
        if(dir=='+'){
         
        }
    }

    

}

void initState(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[0][i][j]='w';
            arr[1][i][j]='y';
            arr[2][i][j]='r';
            arr[3][i][j]='o';
            arr[4][i][j]='g';
            arr[5][i][j]='b';
        }
    }
}

int main(void){
   
    cin>>T;
    int n;
    for(int i=0; i<T; i++){
        initState();
        cin>>n;
        cin.ignore();
        string str;
        for(int j=0; j<n; j++){
            cin>>str;
            rotate(str);
        }

    }


    return 0;
}