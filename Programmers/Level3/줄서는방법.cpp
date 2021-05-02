#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long factorial(int n){
    if(n==1) return 1;
    else return n*factorial(n-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> temp;
    
    for(int i=1; i<=n; i++){
        temp.push_back(i);
    }
    long long fact;
    long long idx;
    
    while(n!=0){
        fact=factorial(n)/n;
        idx=(k-1)/fact;
        answer.push_back(temp[idx]);
        temp.erase(temp.begin()+idx);
        n--;
        k%=fact;
        if(k==0) k=fact;
    }
    
    
    
    return answer;
}