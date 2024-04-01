
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;

    int x;
    int y;
    vector<pair<int,int>> v;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<N; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;

}
