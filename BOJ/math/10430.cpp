#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    
    int A,B,C;

    cin>>A>>B>>C;

    cout<<(A+B)%C<<"\n";
    cout<<((A%C) + (B%C))%C<<"\n";
    cout<<(A*B)%C<<"\n";
    cout<<((A%C)*(B%C))%C<<"\n";


    

    
    return 0;
}