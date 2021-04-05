#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 101
int r,c,k;
int arr[MAX][MAX];
int tmp[MAX][MAX];
int cnt[MAX];

int row, col;


void rowSort(){

    vector< pair<int,int> >v[MAX];
    
    int ncol=col;
    
    memset(tmp,0,sizeof(tmp));

    for(int i=1; i<=row; i++){
        
        memset(cnt,0,sizeof(cnt));
        
        for(int j=1; j<=col; j++){
            if(arr[i][j]!=0){
                cnt[arr[i][j]]+=1;
            }
        }

        for(int j=1; j<=100; j++){
            if(cnt[j]){
                v[i].push_back(make_pair(cnt[j],j));
            }
        }

     
        sort(v[i].begin(), v[i].end());

        int idx=1;

        for(int j=0; j<v[i].size(); j++){

            tmp[i][idx++]=v[i][j].second;
            if(idx==MAX) break;
            tmp[i][idx++]=v[i][j].first;
            if(idx==MAX) break;
        }

        ncol=max(ncol,idx-1);

    }
    col=ncol;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            arr[i][j]=tmp[i][j];
        }
    }

}

void colSort(){

    vector< pair<int,int> >v[MAX];
    
    int nrow=row;
    
    memset(tmp,0,sizeof(tmp));

    for(int i=1; i<=col; i++){
        
        memset(cnt,0,sizeof(cnt));
        
        for(int j=1; j<=row; j++){
            if(arr[j][i]!=0){
                cnt[arr[j][i]]+=1;
            }
        }

        for(int j=1; j<=100; j++){
            if(cnt[j]){
                v[i].push_back(make_pair(cnt[j],j));
            }
        }

     
        sort(v[i].begin(), v[i].end());

        int idx=1;

        for(int j=0; j<v[i].size(); j++){

            tmp[idx++][i]=v[i][j].second;
            if(idx==MAX) break;
            tmp[idx++][i]=v[i][j].first;
            if(idx==MAX) break;
        }

        nrow=max(nrow,idx-1);

    }
    row=nrow;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            arr[i][j]=tmp[i][j];
        }
    }

}

int main(void){
   
    cin>>r>>c>>k;

    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin>>arr[i][j];
        }
    }
    
    row=3;
    col=3;
 
    int answer=0;
    
    while(1){
        if(arr[r][c]==k){
            cout<<answer;
            break;
        }
        if(answer>100){
            cout<<-1;
            break;
        }
        
        if(row>=col){
            rowSort();
        }
        else{
            colSort();
        }
        answer++;

    }


    
    return 0;
}