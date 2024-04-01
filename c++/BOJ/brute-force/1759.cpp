#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 16
int L,C;
char arr[MAX];
char result[MAX];
bool check[MAX];

void dfs(int depth, int start,int mo, int ja){
    if(depth==L){
        if(mo>=1 && ja>=2){
             for(int i=0; i<L; i++){
                cout<<result[i];
            }
             cout<<"\n";
        }
        return;
    }
    if(depth==C) return;

    for(int i=start; i<C; i++){     
        result[depth]=arr[i];
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            dfs(depth+1,i+1,mo+1,ja);
        }
        else{
            dfs(depth+1,i+1,mo,ja+1);
        }        
    }
}
int main(void){
  
    cin>>L>>C;

    for(int i=0; i<C; i++){
        cin>>arr[i];
    }
    sort(arr,arr+C);
    dfs(0,0,0,0);
    



    return 0;
}