#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void BinarySearch(int *arr, int start, int end, int num){
    int mid;
    while(end-start>=0){
        mid=(start+end)/2;

        if(arr[mid]==num){
            cout<<1<<"\n";
            return;
        }
        else if(arr[mid]>num){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<0<<"\n";
    return;
    }
int main(void){
   
    
    return 0;
}