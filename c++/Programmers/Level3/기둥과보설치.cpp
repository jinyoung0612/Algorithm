#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 101
int a[MAX][MAX]; // 기둥
int b[MAX][MAX]; // 보

bool kidoong(int x, int y){
    if(x==0) return true;
    else if(x-1>=0&&a[x-1][y]==1) return true;
    else if(y-1>=0&&b[x][y-1]==1) return true;
    else if(b[x][y]==1) return true;
    return false;
}

bool bo(int x, int y,int n){
    if(x-1>=0&&a[x-1][y]==1) return true;
    else if(x-1>=0&&y+1<=n&&a[x-1][y+1]==1) return true;
    else if((y-1>=0&&b[x][y-1]==1)&&(y+1<=n&&b[x][y+1]==1)) return true;
    return false;
}
vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;
    
    for(int i=0; i<build_frame.size(); i++){
        
        int y=build_frame[i][0];
        int x=build_frame[i][1];
        int type=build_frame[i][2];
        int doing=build_frame[i][3];
        
        // 설치
        if(doing==1){
            // 기둥
            if(type==0){
                if(kidoong(x,y)) a[x][y]=1;
            }
            else{
                if(bo(x,y,n)) b[x][y]=1;
            }
        }
        // 삭제
        else{
            if(type==0){
                
                a[x][y]=0;
          
                bool flag=true;
                
                for(int j=0; j<=n; j++){
                    for(int k=0; k<=n; k++){
                        if(a[j][k]==1&&!kidoong(j,k)) {flag=false; break;}
                        if(b[j][k]==1&&!bo(j,k,n)) {flag=false; break;}
                    }
                }
                
                if(flag==false){
                    a[x][y]=1;
                }
            }
            else{
                
                b[x][y]=0;
                
                bool flag=true;
                
                for(int j=0; j<=n; j++){
                    for(int k=0; k<=n; k++){
                        if(a[j][k]==1&&!kidoong(j,k)) {flag=false; break;}
                        if(b[j][k]==1&&!bo(j,k,n)) {flag=false; break;}
                    }
                }
              
                if(flag==false){
                    b[x][y]=1;
                }
            }
        }
    }
    
    for(int i=0; i<=n; i++){

        for(int j=0; j<=n; j++){
            if(a[i][j]==1){
                vector<int> v;
                v.push_back(j);
                v.push_back(i);
                v.push_back(0);
                answer.push_back(v);
            }
            if(b[i][j]==1){
                vector<int> v;
                v.push_back(j);
                v.push_back(i);
                v.push_back(1);
                answer.push_back(v);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    
    return answer;
}