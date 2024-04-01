
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001
long long road[MAX];
long long prices[MAX];

int main(void){   
    int N;
    
    cin>>N;

    for(int i=0; i<N-1; i++){
        cin>>road[i];
    }
    for(int i=0; i<N; i++){
        cin>>prices[i];
    }

    long long answer=road[0]*prices[0];
    long long cur=prices[0];
    
    for(int i=1; i<N-1; i++){
        cur=min(cur,prices[i]);
        answer+=road[i]*cur;
    }
    cout<<answer;
    


 return 0;

}
