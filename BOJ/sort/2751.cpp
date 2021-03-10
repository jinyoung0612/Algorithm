#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001
int arr[MAX];

int main(void){

   int n;
   cin>>n;
   for(int i=0; i<n; i++){
       cin>>arr[i];
   }
   sort(arr,arr+n);
   
   for(int i=0; i<n; i++){
       cout<<arr[i]<<"\n";
   }
   

    return 0;
}