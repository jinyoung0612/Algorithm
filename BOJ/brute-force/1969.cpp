#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1001

int N,M;

string arr[MAX];
int alpha[4];

char get_max(){
    int max_val=0;
    int idx;
    for(int i=0; i<4; i++){
        if(alpha[i]>max_val){
            max_val=alpha[i];
            idx=i;
        }
        alpha[i]=0;  
    }
    if(idx==0) return 'A';
    else if(idx==1) return 'C';
    else if(idx==2) return 'G';
    else return 'T';
}

int HammingDistance(string a, string b){
    int cnt=0;
    for(int i=0; i<M; i++){
        if(a[i]!=b[i]) cnt+=1;
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    string tmp;
    int answer=0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[j][i]=='A'){
                alpha[0]++;
            }
            else if(arr[j][i]=='C'){
                alpha[1]++;
            }
            else if(arr[j][i]=='G'){
                alpha[2]++;
            }
            else{
                alpha[3]++;
            }
        }
        tmp+=get_max();
    }

    for(int i=0; i<N; i++){
        answer+=HammingDistance(tmp,arr[i]);
    }
    
    cout<<tmp<<"\n";
    cout<<answer;
    return 0;
}