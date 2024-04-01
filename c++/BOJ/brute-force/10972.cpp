#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001
int n;
int arr[MAX];
int result[MAX];
bool check[MAX];

void permutation(int depth){
    if(depth==n){
        for(int i=0; i<n; i++){
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
    

int main(void){

    // cin>>n;
    // vector<int> v(n,0);
    // for(int i=0; i<n; i++){
    //     cin>>v[i];
    // }
    // bool flag=false;
    // while(next_permutation(v.begin(),v.end())){
    //     flag=true;
    //      for(int i=0; i<v.size(); i++){
    //             cout<<v[i]<<" ";
    //         }
    //         break;
    // }
    // if(!flag) cout<<-1;

   int n;
   cin>>n;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=i; j++){
           cout<<'*';
       }
       cout<<"\n";
   }

    return 0;
}