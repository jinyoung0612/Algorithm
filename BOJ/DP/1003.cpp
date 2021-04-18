
#include <iostream>

using namespace std;
#define MAX 41

int fib[MAX];

int main(void){   

    int T;
    cin>>T;
    int N;
    fib[0]=0;
    fib[1]=1;
    fib[2]=1;

    for(int i=3; i<MAX; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    while(T--){
        cin>>N;
        if(N==0){
            cout<<1<<" "<<0<<"\n";
        }
        else if(N==1){
            cout<<0<<" "<<1<<"\n";
        }
        else{
            cout<<fib[N-1]<<" "<<fib[N]<<"\n";
        }

    }

    return 0;

}
