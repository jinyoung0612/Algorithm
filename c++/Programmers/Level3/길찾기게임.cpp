#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> pre,post;
struct Node{
    int num;
    int x;
    int y;
    Node* left;
    Node* right;
};

bool cmp(Node &a, Node &b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y>b.y;
}

void insert(Node *parent, Node *child){
    if(parent->x>child->x){
        if(parent->left==NULL){
            parent->left=child;
        }
        else{
            insert(parent->left,child);
        }
    }
    else{
        if(parent->right==NULL){
            parent->right=child;
        }
        else{
            insert(parent->right,child);
        }
    }
}
void preorder(Node* root){
    if(root){
        pre.push_back(root->num);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->num);
    }
}
vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer;
    int n=nodeinfo.size();
    vector<Node> node;
    
    for(int i=0; i<n; i++){
        Node n={i+1,nodeinfo[i][0],nodeinfo[i][1]};
        node.push_back(n);
    }
    
    sort(node.begin(),node.end(),cmp);
    
    Node* root=&node[0];
    
    for(int i=1; i<n; i++){
        insert(root,&node[i]);
    }
    preorder(root);
    postorder(root);
    
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}