#include <iostream>
#include <vector>

using namespace std;

#define MAX 12

int n;
int arr[MAX];
int op[4];

int max_val=-1000000001;
int min_val=1000000001;

void dfs(int sum,int depth,int plus, int minus, int mult, int div){
    if(depth==n){
        if(sum>max_val) max_val=sum;
        if(sum<min_val) min_val=sum;
        return;
    }
  
    if(plus<op[0]){
        dfs(sum+arr[depth],depth+1,plus+1,minus,mult,div);
    }
    if(minus<op[1]){
        dfs(sum-arr[depth],depth+1,plus,minus+1,mult,div);
    }
    if(mult<op[2]){
        dfs(sum*arr[depth],depth+1,plus,minus,mult+1,div);
    }
    if(div<op[3]){
        dfs(sum/arr[depth],depth+1,plus,minus,mult,div+1);
    }

}

int main(void){
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    dfs(arr[0],1,0,0,0,0);

    cout<<max_val<<"\n"<<min_val;
    
    return 0;
}