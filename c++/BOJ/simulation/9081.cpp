#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void swap(string &str, int i, int j){
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}
int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    string str;
    string temp;

    // 1. next_permutation 사용
    while(T--){
        cin>>str;
        temp=str;
        if(next_permutation(temp.begin(),temp.end())){
            cout<<temp<<"\n";
        }
        else{
            cout<<str<<"\n";
        }
        
    }

    // 2. 구현 (출처: https://tttuer.tistory.com/212)
    while(T--){
        cin>>str;
        int idx=-1;

        // idx는 str[i]<str[i+1]을 만족하는 가장 큰 i
        for(int i=0; i<str.size()-1; i++){
            if(str[i]<str[i+1]) idx=i;
        }
        // idx==-1이면 마지막 순열
        if(idx!=-1){
            int idx2=-1;
            // idx2는 마지막 단어부터 str[idx2]>str[idx]를 만족하는 첫번 째
            for(int j=str.size()-1; j>idx; j--){
                if(str[j]>str[idx]){
                    idx2=j;
                    break;
                }
            }
            // swap
            swap(str,idx,idx2);

            idx++;
            idx2=str.size()-1;
            
            // idx+1부터 마지막까지 정렬하면됨 이때 이미 역순이기 때문에 바꿔주기만 하면 됨
            while(idx<idx2){
                swap(str,idx,idx2);
                idx++;
                idx2--;
            }
        }
        cout<<str<<"\n";
        
    }
    

    return 0;
} 