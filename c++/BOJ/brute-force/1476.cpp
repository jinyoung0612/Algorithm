#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    int E,S,M;
    int cnt=1;

    cin>>E>>S>>M;

    int ne=1; 
    int ns=1;
    int nm=1;

    while(1){

        if(ne==E&&ns==S&&nm==M) break;

        ne++;
        nm++;
        ns++;

        ne = (ne%15==0) ? 15 : ne%15;
        ns = (ns%28==0) ? 28 : ns%28;
        nm = (nm%19==0) ? 19 : nm%19;

        cnt++;

    }
    cout<<cnt;
    return 0;
}