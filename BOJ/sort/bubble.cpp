#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath> 
using namespace std;

#define MAX 1001
int N;
int arr[MAX];

void bubble(){
    for(int i=0; i<N; i++){
        for(int j=1; j<N-i; j++){
            if(arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void selection(){
    int indexMin;
    for(int i=0; i<N-1; i++){
        indexMin=i;
        for(int j=i+1; j<N; j++){
            if(arr[j]<arr[indexMin]){
                indexMin=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[indexMin];
        arr[indexMin]=temp;
    }
}

void insertion(){
    for(int idx=1; idx<N; idx++){
        int temp=arr[idx];
        int prev=idx-1;

        while(prev>=0 && arr[prev]>temp){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=temp;
    }
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    // bubble();
    // selection();
    insertion();
     for(int i=0; i<N; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
} 