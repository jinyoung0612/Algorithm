#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 4000001
int arr[MAX];

int main(void){
    
    int N;
    cin>>N;
    
    if(N==1){
        cout<<0;
        exit(0);
    }
    vector<int> v;
    
    for(int i=2; i<=pow(N,0.5); i++){
        for(int j=i+i; j<=N; j+=i){
            arr[j]=1;
        }
    }
    
    for(int i=2; i<=N; i++){
        if(arr[i]==0){
            v.push_back(i);
        }
    }


    int start=0;
    int end=0;
    int sum=0;
    int answer=0;

    while(start<=end && end!=v.size()+1){
        if(sum<N){
            sum+=v[end++];
        }
        else if(sum==N){
            answer+=1;
            sum-=v[start++];
        }
        else{
            sum-=v[start++];
        }
    }
    cout<<answer;
    
   
    return 0;
}