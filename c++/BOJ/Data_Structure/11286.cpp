
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 100001
int heap[MAX];
int Size=0;

bool Compare(int a, int b){
    int da=abs(a);
    int db=abs(b);
    if(da<=db){
        if(da==db){
            if(a<b) return true;
            return false;
        }
        return true;
    }
    return false;
}

void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void push(int x){

    int idx=++Size;

    while(idx!=1 && Compare(x,heap[idx/2])){
        heap[idx]=heap[idx/2];
        idx/=2;
    }
    
    heap[idx]=x;
    
}

int top(){
    if(Size==0) return 0;

    int value=heap[1];
    heap[1]=heap[Size--];
    int parent=1;
    int child=0;

    while(1){
        child=parent*2;
        if( (child+1<=Size) && Compare(heap[child+1],heap[child]) ) child+=1;
        if(child>Size || Compare(heap[parent],heap[child])) break;

        swap(heap[parent],heap[child]);
        parent=child;
    }
    return value;  
}
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int x;
    cin>>n;

    while(n--){
        cin>>x;

        if(x!=0){
            push(x);
        }
        else{
            cout<<top()<<"\n";
        }
    }
    return 0;

}
