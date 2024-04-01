#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001
int arr[MAX];
void swap(int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    // 1. stl 사용
    // if(prev_permutation(arr,arr+N)){
    //     for(int i=0; i<N; i++){
    //         cout<<arr[i]<<" ";
    //     }
    // }
    // else{
    //     cout<<-1;
    // }
    
    //2. 구현
    int idx=-1;
    for(int i=0; i<N-1; i++){
        if(arr[i]>arr[i+1]) idx=i;
    }
    if(idx==-1){
        cout<<-1;
    }
    else{
        int idx2=-1;

        for(int i=N-1; i>idx; i--){
            if(arr[i]<arr[idx]){
                idx2=i;
                break;
            }
        }
        swap(idx,idx2);
        idx++;
        idx2=N-1;
        while(idx<idx2){
            swap(idx,idx2);
            idx++;
            idx2--;
        }

        for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }

    }
    return 0;
} 