#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 1001
 
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    vector<pair<int,int> > v;
    int s,b;
    int answer=2000000000;
    for(int i=0; i<N; i++){
        cin>>s>>b;
        v.push_back(make_pair(s,b));
    }

    for(int i=1; i<(1<<N); i++){
        int ssum=1;
        int bsum=0;
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                ssum*=v[j].first;
                bsum+=v[j].second;
            }
        }
        answer=min(answer,abs(ssum-bsum));
    }
    cout<<answer;
    
    return 0;
} 