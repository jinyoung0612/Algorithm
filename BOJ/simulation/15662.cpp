#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001

char gear[MAX][8]; // S:1 N:0
bool visited[MAX];
int t; // 톱니 수

void rotation(int num, int dir){
    
    if(!visited[num]){
        visited[num]=1;

        if(num==1&&t>1){
            if(gear[num][2]!=gear[num+1][6]) rotation(num+1,dir*(-1));
        }
        else if(1<num&&num<t){
            if(gear[num-1][2]!=gear[num][6]) rotation(num-1,dir*(-1));
            if(gear[num][2]!=gear[num+1][6]) rotation(num+1,dir*(-1));
        }
        else{
            if(gear[num-1][2]!=gear[num][6]) rotation(num-1,dir*(-1));
        }

        if(dir==1){
            string str=gear[num];
            char temp=str[7];
            for(int i=0; i<7; i++){
                gear[num][i+1]=str[i];
            }
            gear[num][0]=temp;

        }
        else{
            string str=gear[num];
            char temp=str[0];
            for(int i=1; i<8; i++){
                gear[num][i-1]=str[i];
            }
            gear[num][7]=temp;
        }
        
    }
}

int main(void){

    int k;
    int answer=0;

    cin>>t;
    string str;
    for(int i=1; i<=t; i++){
        cin>>str;
        for(int j=0; j<8; j++){
            gear[i][j]=str[j];
        }
    }
    cin>>k;

    int num;
    int dir;

    for(int i=0; i<k; i++){
       cin>>num>>dir;
       rotation(num,dir);
       memset(visited,0,sizeof(visited));
    }

    for(int i=1; i<=t; i++){
        if(gear[i][0]=='1') answer++;
    }
    cout<<answer;

    return 0;
}