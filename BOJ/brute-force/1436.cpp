#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
   
    int N;
    
    cin>>N;
    
    int num=666;
    int cnt=0;
    bool flag;

    // while(cnt!=N){
    //     int temp=num;
    //     flag=false;

    //     while(temp!=0){
    //         if(temp%1000==666){
    //             flag=true;
    //             break;
    //         }
    //         temp/=10;
    //     }
    //     if(flag) cnt++;
    //     num+=1;
    // }
    // cout<<num-1;

    while(1){
        string s=to_string(num);

        if(s.find("666")!=-1){
            cnt+=1;
        }
        if(cnt==N){
            cout<<num;
            break;
        }
        num+=1;
    }
    
    return 0;
}