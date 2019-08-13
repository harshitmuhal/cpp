#include<iostream>
#include<vector>
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

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}

node* levelorderbuild(){
    node *root=NULL;
    queue<node*> q;
    int d;
    cin>>d;
    root=new node(d);
    q.push(root);
    
    while (!q.empty()) {
        node* f=q.front();
        q.pop();
        int left,right;
        cin>>left;
        if(left==-1){
            f->left=NULL;
        }else{
            f->left=new node(left);
            q.push(f->left);
        }
        cin>>right;
        if(right==-1){
            f->right=NULL;
        }else{
            f->right=new node(right);
            q.push(f->right);
        }
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

void printinorder(node *root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

void printpostorder(node *root){
    if(root==NULL){
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}

void printatklevel(node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printatklevel(root->left, k-1);
    printatklevel(root->right, k-1);
}

int height(node*root){
    //return root==NULL?0: 1+max(height(root->left),height(root->right));
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}

void printAllLevels(node*root){
    int levels = height(root);
    
    for(int k=0;k<=levels;k++){
        printatklevel(root,k);
        cout<<endl;
    }
}

int totalnodes(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int count=0;
    count=count+totalnodes(root->left)+totalnodes(root->right)+1;
    
    return count;
}

int sumallnodes(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int sum=0;
    sum=sum+sumallnodes(root->left)+sumallnodes(root->right)+root->data;
    
    return sum;
}

int sumreplace(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL ){
        return root->data;
    }
    int sum=sumreplace(root->left)+sumreplace(root->right);
    int temp=root->data;
    root->data=sum;
    return temp+sum;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1=height(root->left)+height(root->right);
    int op2=max(diameter(root->left),diameter(root->right));
    return max(op1, op2);
}

class mypair{
public:
    int height;
    bool balance;
};

mypair isbalanced(node* root){
    mypair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    mypair l,r;
    l=isbalanced(root->left);
    r=isbalanced(root->right);
    p.height=max(l.height,r.height)+1;
    p.balance=false;
    if(l.balance and r.balance and abs(l.height-r.height)<=1){
        p.balance=true;
    }
    return p;
}

void mirrorimage(node* &root){
    if(root==NULL){
        return;
    }
    
    //swapping
    node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    mirrorimage(root->left);
    mirrorimage(root->right);
    
}

void root2Leaf(node*root,vector<int> &v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        v.push_back(root->data);
        //print the vector
        for(int x:v){
            cout<<x<<"->";
        }
        cout<<endl;
        v.pop_back();
        return;
    }
    //Rec Case
    v.push_back(root->data);
    root2Leaf(root->left,v);
    root2Leaf(root->right,v);
    v.pop_back();
    return;
}

iepair maxsum(node* root){
    iepair p;
    if(root==NULL){
        p.inc=p.exc=0;
        return p;
    }
    iepair l,r;
    l=maxsum(root->left);
    r=maxsum(root->right);
    p.inc=root->data+l.exc+r.exc;
    p.exc=max(l.exc,l.inc)+max(r.inc,r.exc);

    return p;
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

//sample input
//1 2 4 -1 -1 5 6 -1 7 8 -1 -1 -1 9 -1 -1 3 10 -1 13 -1 -1 11 12 14 -1 -1 -1 15 -1 -1

int main(){
    node* root=NULL;
    root=buildtree();
    vector<int> v;
    root2Leaf(root, v);
    return 0;
}