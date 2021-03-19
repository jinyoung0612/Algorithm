#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 10000001


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   vector<int> v;
   int n;
   cin>>n;
   int num;
   for(int i=0; i<n; i++){
       cin>>num;
       v.push_back(num);
   }
   sort(v.begin(),v.end());

   int m;
   int check;
   cin>>m;
   for(int i=0; i<m; i++){
       cin>>check;
       int left=0;
       int right=n-1;
       bool flag=false;

       while(left<=right){
           int mid=(left+right)/2;
           if(v[mid]==check){
               flag=true;
               break;
           }
           else if(v[mid]<check){
               left=mid+1;
           }
           else{
               right=mid-1;
           }
       }
       if(flag) cout<<1<<" ";
       else cout<<0<<" ";
   }

 
    return 0;
}