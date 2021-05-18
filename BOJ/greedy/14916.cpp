#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 31
long long dp[MAX][MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int answer=-1;
    
    if(n%5==0){
        answer=n/5;
    }
    else{
        int temp=n/5;
        while(temp){
            int sum=n-(temp*5);
            if(sum%2==0){
                answer=0;
                answer+=(sum/2);
                answer+=temp;
                break;
            }
            temp--;
            answer--;
        
        }
    }
    cout<<answer;
   
    return 0;
} 