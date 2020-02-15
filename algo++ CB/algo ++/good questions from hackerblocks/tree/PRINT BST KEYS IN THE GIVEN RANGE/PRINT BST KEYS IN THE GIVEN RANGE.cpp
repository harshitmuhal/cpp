#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
    ~node(){
        if(left!=NULL){
            delete left;
        }
        if(right!=NULL){
            delete right;
        }
    }
};

node* insertnodeinbst(node* root,int d){
    //base case
    if(root==NULL){
        return new node(d);
    }
    //rec case
    if(d<root->data){
        root->left=insertnodeinbst(root->left,d);
    }
    else{
        root->right=insertnodeinbst(root->right,d);
    }
    return root;
}

void printpreorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

node* build(int n){
    int d;
    cin>>d;
    node *root=NULL;
    root=insertnodeinbst(root, d);
    n--;
    while(n--){
        cin>>d;
        insertnodeinbst(root, d);
    }
    
    return root;
}

void find(node *root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data<k1 and root->data<k2 ){
        
        find(root->right,k1,k2);
    }
    else if(root->data==k1){
        
        cout<<root->data<<" ";
        find(root->right,k1,k2);
    }
    else if(root->data<k2 and root->data>k1){
        
        find(root->left,k1,k2);
        cout<<root->data<<" ";
        find(root->right,k1,k2);
    }
    else if(root->data==k2){
        
        find(root->left,k1,k2);
        cout<<root->data<<" ";
    }
    else if(root->data>k2){
        find(root->left,k1,k2);
    }
}

int main(){
    node* root=NULL;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        root=build( n);
        cout<<"# Preorder : ";
        printpreorder(root);
        cout<<endl;
        cout<<"# Nodes within range are : ";
        int k1,k2;
        cin>>k1>>k2;
        find(root,k1,k2);
    }
    return 0;
}