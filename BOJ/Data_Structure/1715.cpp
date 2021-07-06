
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100001

int card[MAX];
int main(void){   
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N; i++){
        cin>>num;
        pq.push(num);

    }
    int answer=0;

    while(pq.size()>=2){
        int temp=0;
        int n1=pq.top();
        pq.pop();
        int n2=pq.top();
        pq.pop();
        temp=n1+n2;
        answer+=temp;
        pq.push(temp);
    }

    cout<<answer;
    return 0;

}
