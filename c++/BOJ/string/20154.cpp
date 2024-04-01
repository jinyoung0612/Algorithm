#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main(void){
   
  string str;
  cin>>str;

  int arr[26]={3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

int sum=0;
  for(int i=0; i<str.size(); i++){
      sum=(sum+arr[str[i]-'A']%10);
  }

  sum%2==0 ? cout<<"You're the winner?" : cout<<"I'm a winner!";
  


    return 0;
}