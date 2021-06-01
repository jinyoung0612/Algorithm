#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 501


int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a;
    int b;
    
    while(1){
        cin>>a>>b;
        if(a==0&&b==0) break;
        if(b%a==0){
            cout<<"factor\n";
        }
        else if(a%b==0){
            cout<<"multiple\n";
        }
        else{
            cout<<"neither\n";
        }

    }
   
    return 0;
} 