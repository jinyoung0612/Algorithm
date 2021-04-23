#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 20
#define MIN -pow(2,31)

int N;
string str;
int result=MIN;
int calculate(int a, int b, char sign){
    switch(sign){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
    }
    return 0;
}
void dfs(int depth, int value){
    if(depth>=N){
        result=max(result,value);
        return;
    }
    
    char sign;
    if(depth==0) sign='+';
    else sign=str[depth-1]; 
    
    int temp=calculate(value,str[depth]-'0',sign);
    dfs(depth+2,temp);
    
    if(depth<N-2){
        temp=calculate(str[depth]-'0',str[depth+2]-'0',str[depth+1]);
        temp=calculate(value,temp,sign);
        dfs(depth+4,temp);
    }   
    
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    cin>>str;
    dfs(0,0);
    cout<<result;

    return 0;
} 