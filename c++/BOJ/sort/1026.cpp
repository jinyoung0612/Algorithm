#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 51
vector<int> A;
vector<int> B;

bool cmp(int a, int b){
    return a>b;
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        A.push_back(num);
    }
     for(int i=0; i<N; i++){
        cin>>num;
        B.push_back(num);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),cmp);

    int answer=0;
    for(int i=0; i<N; i++){
        answer+=(A[i]*B[i]);
    }
    cout<<answer;


  

    
    return 0;
} 