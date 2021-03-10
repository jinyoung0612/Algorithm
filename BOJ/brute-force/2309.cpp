#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result[9];
int height[9];
bool flag=false;

void dfs(int start, int end){

    if(end==7){
        int sum=0;
        for(int i=0; i<7; i++){
            sum+=result[i];
        }
        if(sum==100){
            flag=true;
            for(int i=0; i<7; i++){
                cout<<result[i]<<endl;
            }
        }
        return;
    }

    for(int i=start; i<9; i++){
        // cout<<height[i];
        result[end]=height[i];
        dfs(i+1, end+1);
        if(flag) return;
    }
}
int main(void){

    for(int i=0; i<9; i++){
        cin>>height[i];
    }
    sort(height,height+9);

    dfs(0,0);

    return 0;
}