#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char gear[5][8]; // S:1 N:0
bool visited[5];

void rotation(int num, int dir){
    
    if(!visited[num]){
        visited[num]=1;
        if(num==1){
            if(gear[1][2]!=gear[2][6]) rotation(2,dir*(-1));
        }
        else if(num==2){
            if(gear[1][2]!=gear[2][6]) rotation(1,dir*(-1));
            if(gear[2][2]!=gear[3][6]) rotation(3,dir*(-1));
        }
        else if(num==3){
            if(gear[2][2]!=gear[3][6]) rotation(2,dir*(-1));
            if(gear[3][2]!=gear[4][6]) rotation(4,dir*(-1));
        }
        else{
            if(gear[3][2]!=gear[4][6]) rotation(3,dir*(-1));
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
    int score;
    string str;
 
    for(int i=1; i<=4; i++){
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

    if(gear[1][0]=='1') score+=1;
    if(gear[2][0]=='1') score+=2;
    if(gear[3][0]=='1') score+=4;
    if(gear[4][0]=='1') score+=8;

    cout<<score;

    

   
    return 0;
}