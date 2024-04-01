#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 10001

long long lan[MAX];

int main(void){
   
   int k,n;
   cin>>k>>n;

   long long max_val=0;
   for(int i=0; i<k; i++){
       cin>>lan[i];
       max_val=max(max_val,lan[i]);
   }

   long long left=1;
   long long right=max_val;
   long long mid=0;
   long long answer=0;
   
   while(left<=right){
       long long total=0;
       mid=(right+left)/2;
       for(int i=0; i<k; i++){
           if(mid<=lan[i]){
                total+=lan[i]/mid;
           }
       }

       if(total<n){
           right=mid-1;
       }
       else{
           if(answer<=mid) answer=mid;
           left=mid+1;
       }
   }
   cout<<answer;
   
    return 0;
}