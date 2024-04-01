#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    sort(dist.begin(),dist.end());
    
    for(int i=0; i<weak.size(); i++){
        int temp=weak[0]+n;
        for(int j=1; j<weak.size(); j++){
            weak[j-1]=weak[j];
        }
        weak[weak.size()-1]=temp;
        do{
            int idx=0;
            int cnt=0;
            
            for(int k=0; k<dist.size(); k++){
                cnt++;
                int finish=weak[idx]+dist[k];
                while(finish>=weak[idx]&&idx<weak.size()){
                    idx++;
                }
                if(idx==weak.size()) break;
            }
            if(idx==weak.size()){
                if(cnt<answer || answer==-1){
                    answer=cnt;
                }
            }
            
        }while(next_permutation(dist.begin(),dist.end()));
    }
    return answer;
}