#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int findZero(int n){
    string str=to_string(n);
    int cnt=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='0'){
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int N,M;
    cin>>T;
    
    while(T--){
        cin>>N>>M;
        int answer=0;
        for(int i=N; i<=M; i++){
            answer+=findZero(i);
        }
        cout<<answer<<"\n";
    }
    
    return 0;
} 