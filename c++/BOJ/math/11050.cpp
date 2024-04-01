#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// int factorial(int n){
//     if(n==0) return 1;
//     int result=1;
//     for(int i=1; i<=n; i++){
//         result*=i;
//     }
//     return result;
// }

int factorial(int n){
    if(n==1||n==0) return 1;
    return n*factorial(n-1);
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    cout<<factorial(N)/(factorial(N-K)*factorial(K));
    
    return 0;
} 