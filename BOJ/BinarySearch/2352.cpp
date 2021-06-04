#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 40001

int arr[MAX];
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    vector<int> v;
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];

        int idx=lower_bound(v.begin(),v.end(),arr[i])-v.begin();

        if(idx==v.size()){
            v.push_back(arr[i]);
        }
        else{
            v[idx]=arr[i];
        }
    }
    cout<<v.size();
    
    return 0;
} 