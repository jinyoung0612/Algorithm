#include <iostream>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    int N,M;
    
    while(T--){
        cin>>N>>M;
        for(int i=0; i<M; i++){
            int a,b;
            cin>>a>>b;
        }
        cout<<N-1<<"\n";
    }

    return 0;
}