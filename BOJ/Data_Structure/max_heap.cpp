
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100001

int heap[MAX];
int Size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void push(int x){
    
    int idx=++Size;

    while( (idx!=1) && (x>heap[idx/2])){
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
        if(child+1<=Size&&heap[child]<heap[child+1]) child++;
        if(child>Size || heap[child]<heap[parent]) break;

        swap(&heap[parent],&heap[child]);
        parent=child;

    }
    return value;
}

// BOJ 11279 최대 힙
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
