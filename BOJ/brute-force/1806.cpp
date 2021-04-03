#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 100000

int N,S;
int seq[MAX];  

int main(void){
  
    cin>>N>>S;
    
    for(int i=0; i<N; i++){
        cin>>seq[i];
    }
    
    int start=0;
    int end=0;
    int sum=seq[0];
    int answer=987654321;

    while(start<=end&&end<N){
        if(sum<S){
            sum+=seq[++end];
        }
        else if(sum==S){
            answer=min(answer,(end-start+1));
            sum+=seq[++end];
        }
        else if(sum>S){
            answer=min(answer,(end-start+1));
            sum-=seq[start++];
        }
    }

    if(answer==987654321){
        cout<<0;
    }
    else{
        cout<<answer;
    }




    return 0;
}