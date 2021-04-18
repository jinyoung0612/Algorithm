
#include <iostream>

using namespace std;
#define MAX 21
int arr[MAX];
int fib[MAX];

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int fib_dp(int n){
    if(n==0||n==1){
        return n;
    }
    if(fib[n]>0) return fib[n];
    
    fib[n]=fib_dp(n-1)+fib_dp(n-2);
    return fib[n];
}

int main(void){   

    int n;
    cin>>n;
    int answer=0;
    // 1. For Loop
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=n; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    // cout<<arr[n];

    // 2. Recursion
    cout<<fibonacci(n);

    // 3. Memoization
    cout<<fib_dp(n);
    return 0;

}
