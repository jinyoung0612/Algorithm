
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{   
    int N,K;
    string str;
    cin>>N>>K;
    cin>>str;
    
    int answer=0;
    for(int i=0; i<N; i++){
        if(str[i]!='P') continue;

        for(int j=i-K; j<=i+K; j++){
            if(0<=j&&j<N&&str[j]=='H'){
                str[j]='.';
                answer++;
                break;
            }
        }
    }

    cout<<answer;
    

 return 0;
}
