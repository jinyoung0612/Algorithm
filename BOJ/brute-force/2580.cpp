#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 9
int sudoku[MAX][MAX];
bool row[MAX][MAX]; //i번째 행에 j가 존재하는지 확인
bool col[MAX][MAX]; //i번째 열에 j가 존재하는지 확인
bool square[MAX][MAX]; //i번째 3x3 정사각형에 j가 존재하는지 확인

void dfs(int depth){
    if(depth==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
              cout<<sudoku[i][j]<<" ";  
            }
            cout<<"\n";
        }
        exit(0);
    }
    int x=depth/9;
    int y=depth%9;

    if(sudoku[x][y]==0){
        for(int i=1; i<=9; i++){
            if(row[x][i]==0&&col[y][i]==0&&square[(x/3)*3+y/3][i]==0){
                row[x][i]=1;
                col[y][i]=1;
                square[(x/3)*3+y/3][i]=1;
                sudoku[x][y]=i;
                dfs(depth+1);
                row[x][i]=0;
                col[y][i]=0;
                square[(x/3)*3+y/3][i]=0;
                sudoku[x][y]=0;
            }
        }
    }
    else{
        dfs(depth+1);
    }
}
int main(void){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]!=0){
                row[i][sudoku[i][j]]=1;
                col[j][sudoku[i][j]]=1;
                square[(i/3)*3+j/3][sudoku[i][j]]=1;
            }
            
        }
    }
    dfs(0);

    return 0;
}
