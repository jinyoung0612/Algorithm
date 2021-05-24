#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath> 
using namespace std;

#define MAX 101

float arr[MAX][2];
float parent[MAX];

vector<vector<float> >graph;
float getDist(float x1, float y1, float x2, float y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}
void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(void){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string a,b;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr[i][0]=stof(a);
        arr[i][1]=stof(b);
    }
    for(int i=0; i<n; i++){
        parent[i]=i;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            vector<float> temp;
            float dist=getDist(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
            temp.push_back(dist);
            temp.push_back(i);
            temp.push_back(j);
            graph.push_back(temp);
        }
    }
    sort(graph.begin(),graph.end());

    float answer=0;
    for(int i=0; i<graph.size(); i++){
        float dist=graph[i][0];
        int n1=(int)graph[i][1];
        int n2=(int)graph[i][2];

        if(getParent(n1)!=getParent(n2)){
            answer+=dist;
            unionParent(n1,n2);
        }

    }

    cout<<answer;
    
    return 0;
} 