#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000001
int arr[MAX];

void sosoo(){
    arr[0]=1;
    arr[1]=1;
     for(int i=2; i<MAX; i++){
        if(i%2==0){
            arr[i]=1;
        }
    }
    for(int i=2; i<MAX; i++){
        for(int j=i+i; j<MAX; j+=i){
            if(arr[j]==0){
                arr[j]=1;
            }
        }
    }
}

int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a,b;
    sosoo();
    while(1){
        cin>>n;
        a=0;
        b=0;
        if(n==0) break;

        for(int i=2; i<n; i++){
            if(arr[i]==0&&arr[n-i]==0){
                a=i;
                b=n-i;
                break;
            }
        }
        if(a==0&&b==0){
            cout<<"Goldbach's conjecture is wrong\n";
        }
        else{
            cout<<n<<" = "<<a<<" + "<<b<<"\n";
        }

    }
   
    
   
    return 0;

}
