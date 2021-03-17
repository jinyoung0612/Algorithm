#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int N;
    cin>>N;
    int len=0;
    int temp=N;
    while(temp>0){
        temp/=10;
        len++;
    }
    int answer=0;
    for(int i=len; i>=1; i--){
        if(i==len){
            answer=(N-pow(10,i-1)+1)*i;
        }
        else{
            answer=answer+(9*pow(10,i-1))*i;
        }
    }
    cout<<answer;

    return 0;
}