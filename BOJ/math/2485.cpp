#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100001
int arr[MAX];
int temp[MAX];

int gcd(int a, int b){
    if(b!=0){
        return gcd(b,a%b);
    }
    return a;
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        arr[i]=num;
    }
    for(int i=1; i<N; i++){
        temp[i-1]=arr[i]-arr[i-1];
    }
    int min_interval=987654321;
    for(int i=1; i<N-1; i++){  
        min_interval=min(min_interval,gcd(temp[i-1],temp[i]));
    }

    int answer=0;
    for(int i=0; i<N-1; i++){
        if(arr[i+1]-arr[i]!=min_interval){
            answer+=((arr[i+1]-arr[i])/min_interval-1);
        }
    }
    cout<<answer;
    
    return 0;
} 