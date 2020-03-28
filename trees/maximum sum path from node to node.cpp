#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(){
        left=right=NULL;
    }
};
node* levelorderinput(){
    node *root=new node;
    int d;cin>>d;
    root->data=d;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            f->left=new node;
            f->left->data=c1;
            q.push(f->left);
        }
        if(c2!=-1){
            f->right=new node;
            f->right->data=c2;
            q.push(f->right);
        }
    }
    return root;
}
int globalmax=INT_MIN;
int MaxSumpathfromNode2Node(node* root){
    if(root==NULL){
        return 0;
    }
    int l=MaxSumpathfromNode2Node(root->left);
    int r=MaxSumpathfromNode2Node(root->right);
    globalmax=max(ls+root->data,max(rs+root->data,max(ls+rs+root->data,max(root->data,globalmax))));
    return max(ls,max(rs,0))+root->data;
}
int main(){
    node *root=levelorderinput();
    printlevelorder(root);
    globalmax=INT_MIN;
    MaxSumpathfromNode2Node(root);
    cout<<globalmax<<endl;
    return 0;
}