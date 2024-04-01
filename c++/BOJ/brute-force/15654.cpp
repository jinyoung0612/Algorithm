#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9

int n,m;
int arr[MAX]={0,};
bool check[MAX]={0,};
int result[9];

void permutation(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<n; i++){
        if(!check[i]){
            check[i]=1;
            result[depth]=arr[i];
            permutation(depth+1);
            check[i]=0;
        }
    }
    

}
void dupPermutation(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<n; i++){
        result[depth]=arr[i];
        dupPermutation(depth+1);
    }
}
void combination(int depth, int start){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=start; i<n; i++){
        result[depth]=arr[i];
        combination(depth+1, i+1);
    }
}
void dupCombination(int depth, int start){
    if(depth==m){
        for(int i=0 ;i<m; i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=start; i<n; i++){
        result[depth]=arr[i];
        dupCombination(depth+1,i);
    }
}
int main(void){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    // permutation(0);
    // combination(0,0);
    // dupPermutation(0);
    dupCombination(0,0);
    return 0;
}