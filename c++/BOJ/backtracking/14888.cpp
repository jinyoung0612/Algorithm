#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[12];
int op[4]; // + - * /
bool visited[12];
int Select[12];
int max_val=-1000000000;
int min_val=1000000000;
void permutation(int depth){

    if(depth==N-1){
        int sum=arr[0];

        for(int i=0; i<N-1; i++){
            if(Select[i]==0){
                sum+=arr[i+1];
            }
            else if(Select[i]==1){
                sum-=arr[i+1];
            }
            else if(Select[i]==2){
                sum*=arr[i+1];
            }
            else{
                sum/=arr[i+1];
            }
        }
        max_val=max(max_val,sum);
        min_val=min(min_val,sum);
        return;
    }

    for(int i=0; i<4; i++){
        if(op[i]>0){
            Select[depth]=i;
            op[i]--;
            permutation(depth+1);
            op[i]++;
        }
    }
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    permutation(0);
    cout<<max_val<<"\n";
    cout<<min_val<<"\n";
    return 0;
} 