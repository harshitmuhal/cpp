#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int span[n];
	span[0]=1;
	stack<pair<int,int>>s;
	s.push({0,v[0]});
	for(int i=1;i<n;i++){
		while(!s.empty() and s.top().second<=v[i]){
			s.pop();
		}
		if(s.empty()){
			span[i]=i+1;
		}
		else{
			span[i]=i-s.top().first;
		}
		s.push({i,v[i]});
	}
	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	cout<<"END";
	return 0;
}