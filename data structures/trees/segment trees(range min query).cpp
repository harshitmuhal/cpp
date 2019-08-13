#include<iostream>
#include<climits>

using namespace std;

void buildtree(int *tree,int *arr,int index,int s,int e){
    
    //s,e is node range and index is index pos of tree array.
    //base case - leaf node reached
    if(s==e){
        tree[index]=arr[s];
        return;
    }
    
    //rec case
    int mid=(s+e)/2;
    //left subtree
    buildtree(tree,arr,2*index,s,mid);
    //right subtree
    buildtree(tree,arr,2*index+1,mid+1,e);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int query(int *tree,int index,int s,int e,int qs,int qe){
    //base case 1 - no overlap
    if(qe<s||qs>e){
        return INT_MAX;
    }
    //base case 2 - complete overlap
    if(qs<=s && qe>=e){
        return tree[index];
    }
    
    //rec case- partial overlap
    int mid=(s+e)/2;
    int left=query(tree,2*index,s,mid,qs,qe);
    int right=query(tree,2*index+1,mid+1,e,qs,qe);
    return min(left,right);
}

void updatenode(int *tree,int *arr,int index,int s,int e,int i,int val){
    //no overlap
    if(i<s or i>e){
        return;
    }
    //reached leaf node
    if(s==e){
        tree[index]+=val;
        arr[s]+=val;
        return;
    }
    int mid=(s+e)/2;
    updatenode(tree,arr,2*index,s,mid,i,val);
    updatenode(tree,arr,2*index+1,mid+1,e,i,val);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void updaterange(int *tree,int *arr,int index,int s,int e,int rs,int re,int val){
    //no overlap
    if(re<s or rs>e){
        return;
    }
    //reached leaf node
    if(s==e){
        tree[index]+=val;
        arr[s]+=val;
        return;
    }
    int mid=(s+e)/2;
    updaterange(tree,arr,2*index,s,mid,rs,re,val);
    updaterange(tree,arr,2*index+1,mid+1,e,rs,re,val);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main(){
    int n;
    cin>>n;
    //int arr[]={1,-2,4,0,5};
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int tree[4*n+1];
    buildtree(tree,arr,1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int qs,qe;
        cin>>qs>>qe;
        cout<<query(tree,1,0,n-1, qs,qe)<<"\n";
        updaterange(tree, arr,1,0, n-1,0,1,-1);
        cout<<query(tree,1,0,n-1, qs,qe)<<"\n";
    }
    
    return 0;
}