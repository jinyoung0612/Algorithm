
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

int arr1[MAX];
int arr2[MAX];

int main(void){   

string a,b;
cin>>a>>b;
string result;

if(a.size()<b.size()){
    string tmp=b;
    b=a;
    a=tmp;
}

//둘중에 더 긴 수
for(int i=1; i<=a.size(); i++){
    arr1[i]=a[i-1]-'0';
}

for(int i=1; i<=b.size(); i++){
    arr2[i+(a.size()-b.size())]=b[i-1]-'0';
}

for(int i=a.size(); i>0; i--){
    int sum=arr1[i]+arr2[i];
    if(sum>=10){
        arr1[--i]+=1;
        i++;
        result=char(sum%10+'0')+result;
    }
    else{
        result=char(sum+'0')+result;
    }
}
if(arr1[0]!=0){
    result='1'+result;
}
cout<<result;


 return 0;

}
