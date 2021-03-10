#include <iostream>
#include <vector>

using namespace std;

#define MAX 9

int n,m;
int arr[MAX]={0,};
bool check[MAX]={0,};
void permutation(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(!check[i]){
            check[i]=1;
            arr[depth]=i;
            permutation(depth+1);
            check[i]=0;
        }
    }
}
void duplicatePermutation(int depth){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1; i<=n; i++){
            arr[depth]=i;
            duplicatePermutation(depth+1);
    }
}
void combination(int depth, int start){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

     for(int i=start; i<=n; i++){
         arr[depth]=i;
         combination(depth+1,i+1);
    }
}

void duplicateCombination(int depth, int start){
    if(depth==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

     for(int i=start; i<=n; i++){
         arr[depth]=i;
         duplicateCombination(depth+1,i);
    }
}

int main(void){
    
    cin>>n>>m;
    // permutation(0);
    // combination(0,1);
    // duplicatePermutation(0);
    duplicateCombination(0,1);
    return 0;
}