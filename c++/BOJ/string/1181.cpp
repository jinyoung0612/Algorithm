#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1001

bool cmp(string a, string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    else{
        return a<b;
    }
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<string> v;
    string str;
    while(N--){
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),cmp);


    for(int i=0; i<v.size(); i++){
        if(i>0&&v[i]==v[i-1]) continue;
        cout<<v[i]<<"\n";
    }

    return 0;
} 