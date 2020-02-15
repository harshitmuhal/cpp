#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

void levelorderbfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        
        node*f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left!=NULL)
                q.push(f->left);
            if(f->right!=NULL)
                q.push(f->right);
        }
    }
    
}

void hashing(node *root,int d,map<int ,vector<int> > &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    hashing(root->left,d-1,m);
    hashing(root->right,d+1,m);
    
}


int main() {
    int n;
    cin>>n;
    node *root=NULL;
    root=levelorderbuild();
    //levelorderbfs(root);
    map<int ,vector<int>> m;
    hashing(root,0,m);
    for(auto x:m){
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
