#include<bits/stdc++.h>
using namespace std;

vector<int>v;
void printsubsequences(int arr[],int n,int i){
	if(i>=n){
		if(v.size()==0){
			cout<<endl;
			return;
		}
		for(int i=0;i<=v.size()-1;i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return;
	}
	v.push_back(arr[i]);
	printsubsequences(arr,n,i+1);
	v.pop_back();
	printsubsequences(arr,n,i+1);
}
int main(){

	int arr[]={1,2,3,4,5};
	printsubsequences(arr,5,0);
	return 0;
}