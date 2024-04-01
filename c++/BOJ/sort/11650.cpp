#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    vector<pair<int,int>> v;
    int x;
    int y;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

    return 0;
} 