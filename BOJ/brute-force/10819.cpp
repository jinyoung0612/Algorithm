#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
    int N;
    cin>>N;
    vector<int> input(N,0);
    vector<int> answer;
  
    for(int i=0; i<N; i++){
        cin>>input[i];
    }

    sort(input.begin(),input.end());

    do{
        int sum=0;
        for(int i=0; i<N-1; i++){
            sum+=abs(input[i]-input[i+1]);
        }
        answer.push_back(sum);

    }while(next_permutation(input.begin(),input.end()));

    cout<<*max_element(answer.begin(),answer.end());
    
    return 0;
}