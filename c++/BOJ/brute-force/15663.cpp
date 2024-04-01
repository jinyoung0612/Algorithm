#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9

int n,m;
int arr[MAX]={0,};
bool check[MAX]={0,};
int result[MAX]={0,};

void func(int depth){

    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }   
        cout<<"\n";
        return;
    }
    int prev=-1;

    for(int i=0; i<n; i++){
        if(!check[i]&&(prev!=arr[i])){
            check[i]=1;
            prev=arr[i];
            result[depth]=arr[i];
            func(depth+1);
            check[i]=0;
       }
    }
}

void func2(int depth, int start){
    int prev2=-1;

    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }   
        cout<<"\n";
        return;
    }

    for(int i=start; i<n; i++){
        if(prev2!=arr[i]){
            prev2=arr[i];
            result[depth]=arr[i];
            func2(depth+1,i+1);
        }
    }

}

void func3(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }   
        cout<<"\n";
        return;
    }
    int prev3=-1;

    for(int i=0; i<n; i++){
        if(prev3!=arr[i]){
            prev3=arr[i];
            result[depth]=arr[i];
            func3(depth+1);
       }
    }
}

void func4(int depth, int start){
    int prev4=-1;

    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }   
        cout<<"\n";
        return;
    }

    for(int i=start; i<n; i++){
        if(prev4!=arr[i]){
            prev4=arr[i];
            result[depth]=arr[i];
            func4(depth+1,i);
        }
    }

}

int main(void){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    // func(0);
    // func2(0,0);
    // func3(0);
    func4(0,0);
    return 0;
}