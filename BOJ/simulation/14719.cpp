#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 501
int arr[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H,W;
    cin>>H>>W;
    int answer=0;
    for(int i=0; i<W; i++){
        cin>>arr[i];
    }
    
    for(int i=1; i<W-1; i++){
        int left=0;
        int right=0;

        for(int j=0; j<i; j++){
            left=max(left,arr[j]);
        }

        for(int j=i+1; j<W; j++){
            right=max(right,arr[j]);
        }
        int result=min(left,right);

        if(result-arr[i]>0){
            answer+=(result-arr[i]);
        }
    }
    cout<<answer;
    

    

    return 0;
} 