#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

char arr[5][16];

int main(void){
    int max_len=0;
    string str;
    // for(int i=0; i<5; i++){
    //    cin>>str;
    //    for(int j=0; j<str.size(); j++){
    //        arr[i][j]=str[j];
    //    }
    //    max_len=max(max_len,(int)str.size());
    // }

    // for(int i=0; i<max_len; i++){
    //     for(int j=0; j<5; j++){
    //         string tmp=arr[j];
    //         if(tmp.size()<=i) continue;
    //         cout<<arr[j][i];
    //     }
    // }

    for(int i=0; i<5; i++){
       cin>>arr[i];
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(arr[j][i]==NULL) continue;
            cout<<arr[j][i];
        }
    }
    return 0;
}