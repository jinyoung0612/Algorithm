#include <iostream>
#include <vector>

using namespace std;
vector<pair<int,int> > v;
void hanoi(int n, int from , int temp, int to){
    if(n==1){
        v.push_back(make_pair(from,to));
        return;
    }
    hanoi(n-1,from, to ,temp);
    v.push_back(make_pair(from,to));
    hanoi(n-1,temp,from,to);
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int K;
    cin>>K;
    hanoi(K,1,2,3);
    cout<<v.size()<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

    return 0;
} 