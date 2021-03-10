#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[13];
int result[13];
int k;

void dfs(int start, int depth){
    if(depth==6){
        for(int i=0; i<6; i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=start; i<k; i++){
        result[depth]=s[i];
        dfs(i+1,depth+1);
    }
}

int main(void){

    cin>>k;
  
    while(k!=0){
       
       for(int i=0; i<k; i++){
           cin>>s[i];
       }
    
        dfs(0,0);
        cout<<endl;
       
        cin>>k;
    }
    return 0;
}