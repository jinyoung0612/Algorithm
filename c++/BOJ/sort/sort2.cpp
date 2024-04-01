#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath> 
using namespace std;

#define MAX 1000001
int N;

void swap(int *arr,int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void quick_sort(int *arr, int left, int right){
    if(left>=right) return;

    int key=left;
    int i=left+1;
    int j=right;

    while(i<=j){
        while(i<=right&&arr[i]<=arr[key]){
            i++;
        }
        while(j>left&&arr[j]>=arr[key]){
            j--;
        }
        if(i>j){
            swap(arr,j,key);
        }
        else{
            swap(arr,i,j);
        }
    }
   
    quick_sort(arr,left,j-1);
    quick_sort(arr,j+1,right);
    
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    int arr[MAX];

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    quick_sort(arr,0,N-1);
    
    for(int i=0; i<N; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
} 