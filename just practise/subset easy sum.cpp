#include<iostream>
using namespace std;

void fn(int arr[],output,int j,int n,int i,vector<int> v[],int p){
if(i>=n){
	v.push_back(output);
	p++;
	return p;
}

output[j]=arr[i];
p+=fn(arr,output,j+1,n,i+1,p);
p+=fn(arr,output,j,n,i+1,p);
return p;
}


int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int output[n];
		int z=1<<n;
		vector<int> v[z];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int p=fn(arr,output,0,n,0,0)
		for(int x=0;x<p;x++){
			
		}
	}
	return 0;
}