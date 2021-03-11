#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,x,y;
int GCD(int a, int b){
    if(a%b==0){
        return b;
    }
    return GCD(b,a%b);
}
int LCM(int a, int b){
    return (a*b)/GCD(a,b);
}
int main(void){

   int t;
   cin>>t;
 
//    for(int i=0; i<t; i++){
//        cin>>m>>n>>x>>y;
//        int max_year=LCM(m,n);

//         while(1)
//         {
//             if(x>max_year || (x-1)%n+1==y) break;

//             x+=m;
//         }

//         if(x>max_year) cout<<-1<<"\n";
//         else cout<<x<<"\n";
//    } 
   for(int i=0; i<t; i++){
       cin>>m>>n>>x>>y;
       int max_year=LCM(m,n);
       bool flag=false;

       for(int j=x; j<=max_year; j+=m){
           int tmp=(j%n==0) ? n : j%n;
           if(tmp==y){
               cout<<j<<"\n";
               flag=true;
               break;
           }
       }
       if(!flag) cout<<-1<<"\n";

   }   
     
   
    return 0;
}