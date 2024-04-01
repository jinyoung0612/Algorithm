#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 1001
int N;
vector<int> arr;
int answer=0;
int energy;
void dfs(int depth){
   
    if(depth==N-2){
        answer=max(answer,energy);
        return;
    }

    for(int i=1; i<arr.size()-1; i++){
        int select=arr[i];
        energy+=(arr[i-1]*arr[i+1]);
        arr.erase(arr.begin()+i);
        dfs(depth+1);
        arr.insert(arr.begin()+i,select);
        energy-=(arr[i-1]*arr[i+1]);
    }

    
}
int main(void){
    cin>>N;
    int num;
    for(int i=0; i<N; i++){
        cin>>num;
        arr.push_back(num);
    }


   dfs(0);
   cout<<answer;
   
    return 0;
}