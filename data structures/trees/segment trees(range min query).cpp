#include<iostream>

using namespace std;

void buildtree(int *tree,int *arr,int index,int s,int e){ 
	
	//s,e is node range and index is index pos of tree array.
	
	if(s>e){
		return;
	}
	//base case - leaf node reached
	if(s==e){
		tree[index]=arr[s];
	}

	//rec case
	int mid=(s+e)/2;
	//left subtree
	buildtree(tree,arr,2*index,s,mid);
	//right subtree
	buildtree(tree,arr,2*index+1,mid+1,e);
	tree[index]=min(tree[2*index],tree[2*index+1])
}

int query(int *tree,int index,int s,int e,int qs,int qe){
	//base case 1 - no overlap
	if(qe<s||qs>e){
		return INT_MAX;
	}
	//base case 2 - complete overlap
	if(qs && e==qe){
		return tree[index];
	}

	//rec case- partial overlap
	int mid=(s+e)/2;
	query(tree,2*index,s,mid)
}

int main(){
	int n;
	cin>>n;
	//int arr[]={1,-2,4,0,5};
	int arr;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int tree[4*n+1];
	buildtree(tree,arr,1,0,n-1);
	int q;
	cin>>q;
	while(q--){
		int qs,qe;
		cin>>qs>>qe;
	}

	return 0;
}