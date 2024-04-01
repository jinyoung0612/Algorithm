
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10001

int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int x;
    priority_queue<int , vector<int>, less<int> > pq;
    cin>>n;

    while(n--){
        cin>>x;

        if(x!=0){
            pq.push(x);
        }
        else{
            cout<<(pq.empty() ? 0 : pq.top())<<"\n";
            if(!pq.empty()) pq.pop();
        }
    }
    return 0;

}
