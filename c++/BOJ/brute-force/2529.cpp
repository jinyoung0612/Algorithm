// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// char arr[10];
// int num[10];
// int k;
// bool check[10];
// vector<string> v;
// void permutation(int depth){
//     if(depth==k+1){
     
//         bool flag=true;
//         for(int i=1; i<=k; i++){
//             if(arr[i]=='<'){
//                 if(num[i-1]>num[i]) flag=false;
//             }
//             else{
//                 if(num[i-1]<num[i]) flag=false;
//             }
//         }

//         if(flag){
//             string str;
//             for(int i=0; i<k+1; i++){
//                 str+=(num[i]+'0');
//             }
//             v.push_back(str);
//         }
//         return;
//     }
//     for(int i=0; i<10; i++){
//         if(!check[i]){
//             check[i]=1;
//             num[depth]=i;
//             permutation(depth+1);
//             check[i]=0;
//         }
//     }
// }
// int main(void){
//     cin>>k;
//     for(int i=1; i<=k; i++){
//         cin>>arr[i];
//     }
//     permutation(0);
//     cout<<v[v.size()-1]<<"\n";
//     cout<<v[0]<<"\n";
//     return 0;
// }

//더 효율적인 풀이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[10];
int k;
bool check[10];
vector<string> v;

bool isValid(string num){
    for(int i=1; i<=k; i++){
        if(arr[i]=='<'){
            if(num[i-1]>num[i]) return false;
        }
        else{
            if(num[i-1]<num[i]) return false;
        }
    }
    return true;
}
int main(void){
    cin>>k;
    for(int i=1; i<=k; i++){
        cin>>arr[i];
    }
    
    string max_num;
    string min_num;

    for(int i=9; i>9-(k+1); i--){
        max_num+=(i+'0');
    }
     for(int i=0; i<k+1; i++){
        min_num+=(i+'0');
    }

    do{
        if(isValid(max_num)) break;

    }while(prev_permutation(max_num.begin(),max_num.end()));

    do{
        if(isValid(min_num)) break;
        
    }while(next_permutation(min_num.begin(),min_num.end()));

    cout<<max_num<<"\n";
    cout<<min_num<<"\n";
    return 0;
}