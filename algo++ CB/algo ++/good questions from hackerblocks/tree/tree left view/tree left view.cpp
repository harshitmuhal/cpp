#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

node* levelorderbuild(){
    queue<node*> q;
    int d;
    cin>>d;
    node* root=new node(d);
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        cin>>d;
        if(d!=-1){
            temp->left=new node(d);
            q.push(temp->left);
        }else{
            temp->left=NULL;

        }
        cin>>d;
        if(d!=-1){
            temp->right=new node(d);
            q.push(temp->right);
        }else{
            temp->right=NULL;
        }
    }
    return root;
}

 void print(node*root,int level,int &maxlevel){
     if(root==NULL){
         return;
     }
     if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
     }
     print(root->left,level+1,maxlevel);
     print(root->right,level+1,maxlevel);
 }

int main() {
  
    node *root=NULL;
    root=levelorderbuild();
    int max=0;
    print(root,1,max);
    return 0;
}