#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void){
   int x,y,w,h;
   cin>>x>>y>>w>>h;
    cout<<min(min(abs(0-x),abs(x-w)),min(abs(y-h),abs(y-0)));
    return 0;
}