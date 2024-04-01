#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 100001

int remote[11];
 
bool check(int num){
    string str=to_string(num);
    for(int i=0; i<str.size(); i++){
        if(remote[str[i]-'0']==1){
            return false;
        }
    }
    return true;
}

int main(void){
    int n, m;
    cin>>n>>m;
    int num;
    for(int i=0; i<m; i++){
        cin>>num;
        remote[num]=1;
    }

    string str=to_string(n);
    int min_val=abs(n-100);

    for(int i=0; i<=1000001; i++){
        if(check(i)){
            int temp=abs(n-i)+to_string(i).length();
            min_val=min(min_val,temp);

        }
    }
    cout<<min_val;

    return 0;
}