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

node* arraytobst(node* root,int arr[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    root=insertnodeinbst(root, arr[mid]);
    root->left=arraytobst(root->left, arr, s, mid-1);
    root->right=arraytobst(root->right, arr,mid+1,e);

    return root;
}

istream& operator>>(istream &is,node* &root){
    int d;
    cin>>d;
    while (d!=-1) {
        root=insertnodeinbst(root, d);
        cin>>d;
    }
    return is;
}

node* pretobst(int *pre,int *in,int s,int e){
    //base case
    if(s>e){
        return NULL;
    }

    static int i=0;
    node * root=new node(pre[i]);
    
    //find the index of pre[i] in inorder array
    int j;
    for(int j=s;j<=e;j++){
        if(pre[j]==in[j]){
            break;
        }
    }

    i++;
    root->left=pretobst(pre,in,s,j-1);
    root->right=pretobst(pre,in,j+1,e);

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

ostream& operator<<(ostream &os,node* root){

    levelorderbfs(root);
    cout<<endl;
    return os;
}

node* deletenodeinbst(node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    //rec case
    if(root->data==key){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL){
            node* temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deletenodeinbst(root->right,temp->data);
            return root;
        }
    }
    else{
        if(key<root->data){
            root->left=deletenodeinbst(root->left,key);

        }
        else{
            root->right=deletenodeinbst(root->right,key);

        }
    }
    return root;
}

bool search(node* root,int key){
    //base case
    if(root==NULL){
        return false;
    }
    //rec case
    bool ans;
    if(root->data==key){
        return true;
    }
    else if(key<root->data){
        ans=search(root->left,key);
    }
    else{
        ans=search(root->right,key);
    }
    return ans;
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

class iepair{
public:
    int inc;
    int exc;
};

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

//sample input
//5 3 8 0 2 7 10 6 -1


int main(){
    node* root=NULL;
    int arr[5]={1,2,3,4,5};
    root=arraytobst(root,arr,0,4);
    cout<<root;
    return 0;
}