#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 20

int N;
int arr[MAX][MAX];
int answer=0;

void Up(){
    
    queue<int> q;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[j][i]!=0){
                q.push(arr[j][i]);
            }
            arr[j][i]=0;
        }
        int idx=0;

        while(!q.empty()){
            int num=q.front();
            q.pop();
            
            if(arr[idx][i]==0){
                arr[idx][i]=num;
            }
            else if(arr[idx][i]==num){
                arr[idx][i]*=2;
                idx++;
            }
            else{
                idx++;
                arr[idx][i]=num;
            }
        }
    }
}

void Down(){

     queue<int> q;

    for(int i=0; i<N; i++){
        for(int j=N-1; j>=0; j--){
            if(arr[j][i]!=0){
                q.push(arr[j][i]);
            }
            arr[j][i]=0;
        }

        int idx=N-1;

        while(!q.empty()){
            int num=q.front();
            q.pop();
            
            if(arr[idx][i]==0){
                arr[idx][i]=num;
            }
            else if(arr[idx][i]==num){
                arr[idx][i]*=2;
                idx--;
            }
            else{
                idx--;
                arr[idx][i]=num;
            }
        }
    }
}

void Left(){
    queue<int> q;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]!=0){
                q.push(arr[i][j]);
            }
            arr[i][j]=0;
        }

        int idx=0;

        while(!q.empty()){
            int num=q.front();
            q.pop();
            
            if(arr[i][idx]==0){
                arr[i][idx]=num;
            }
            else if(arr[i][idx]==num){
                arr[i][idx]*=2;
                idx++;
            }
            else{
                idx++;
                arr[i][idx]=num;
            }
        }
    }

    
}

void Right(){

    queue<int> q;

    for(int i=0; i<N; i++){
        for(int j=N-1; j>=0; j--){
            if(arr[i][j]!=0){
                q.push(arr[i][j]);
            }
            arr[i][j]=0;
        }

        int idx=N-1;

        while(!q.empty()){

            int num=q.front();
            q.pop();
            
            if(arr[i][idx]==0){
                arr[i][idx]=num;
            }
            else if(arr[i][idx]==num){
                arr[i][idx]*=2;
                idx--;
            }
            else{
                idx--;
                arr[i][idx]=num;
            }
        }
    }
   
}

void dfs(int cnt){

     

    if(cnt==5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                answer=max(answer,arr[i][j]);
            }
        }
        return;
    }
    int temp[MAX][MAX];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j]=arr[i][j];
        }
    }

    for(int i=0; i<4; i++){
        switch(i){
            case(0): 
                Up(); 
                dfs(cnt+1);
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        arr[i][j]=temp[i][j];
                        }
                    }; 
                break;

            case(1): 
                Down(); 
                dfs(cnt+1);
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        arr[i][j]=temp[i][j];
                        }
                    };  
                break;
            case(2): 
                Left(); 
                dfs(cnt+1); 
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        arr[i][j]=temp[i][j];
                        }
                    }; 
                break;
            case(3): 
                Right(); 
                dfs(cnt+1); 
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        arr[i][j]=temp[i][j];
                        }
                    };
                break;

        }
    }
}

int main(void){

    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    dfs(0);
    cout<<answer;

    return 0;
}
