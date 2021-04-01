#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int N;
    cin>>N;

    string str;
    cin>>str;

    int answer=0;
    for(int i=0; i<N; i++){
        answer+=(str[i]-'0');
    }

    cout<<answer;
    return 0;
}