// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// #define MAX 100001

/* 1. STL 사용 */
// int main(void){
//     int N;
//     int num;
//     string s;
//     cin>>N;
//     queue<int> q;

//     for(int i=0; i<N; i++){
//         cin>>s;
//         if(s=="push"){
//             cin>>num;
//             q.push(num);
//         }
//         else if(s=="pop"){
//             if(!q.empty()){
//                 cout<<q.front()<<endl;
//                 q.pop();
//             }
//             else{
//                 cout<<-1<<endl;;
//             }
//         }
//         else if(s=="size"){
//             cout<<q.size()<<endl;
//         }
//         else if(s=="empty"){
//             q.empty() ? cout<<1 : cout <<0;
//             cout<<endl;
//         }
//         else if(s=="front"){
//             q.empty() ? cout<< -1 : cout <<q.front();
//             cout<<endl;
//         }
//         else if(s=="back"){
//             if(q.empty()){
//                 cout<<-1<<endl;
//             }
//             else{
//                 cout<<q.back()<<endl;
//             }
//         }
//     }
//     return 0;
// }

/* 2. struct 사용 */

// #define MAX 2000001
// int queue[MAX];
// int front=-1;
// int rear=-1;

// void push(int x){
//     queue[++rear]=x;
// }
// void pop(){
//     if(front==rear){
//         cout<<-1<<"\n";
//     }
//     else{
//         cout<<queue[++front]<<"\n";
//     }
// }
// void Size(){
//     if(front==rear){
//         cout<<0<<"\n";
//     }
//     else{
//         cout<<rear-front<<"\n";
//     }
// }
// void empty(){
//     if(front==rear){
//         cout<<1<<"\n";
//     }
//     else{
//         cout<<0<<"\n";
//     }
// }
// void Front(){
//     if(front==rear) cout<<-1<<"\n";
//     else cout<<queue[front+1]<<"\n";
// }
// void back(){
//     if(front==rear) cout<<-1<<"\n";
//     else cout<<queue[rear]<<"\n";
// }

// int main(void){
    
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int N;
//     cin>>N;
//     string str;
//     while(N--){
//         cin>>str;
//         if(str=="push"){
//             int num;
//             cin>>num;
//             push(num);

//         }
//         else if(str=="front"){
//             Front();
//         }
//         else if(str=="back"){
//             back();
//         }
//         else if(str=="size"){
//             Size();
//         }
//         else if(str=="empty"){
//             empty();
//         }
//         else if(str=="pop"){
//             pop();
//         }
//     }
//     return 0;
// } 


/* 3. Circular Queue 사용 */

/* 4. Stack 2개로 Queue 구현 */

