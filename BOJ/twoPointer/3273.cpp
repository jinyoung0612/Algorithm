#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001
int arr[MAX];
int main(void){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    int answer=0;
    
    sort(arr,arr+n);

    for(int i=0; i<n; i++){
        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]+arr[i]==x){
                answer++;
                break;
            }
            else if(arr[mid]+arr[i]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    cout<<answer/2;

    
    return 0;
}