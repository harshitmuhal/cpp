#include<bits/stdc++.h>
using namespace std;
void display(stack<int>s){
	while(!s.empty()){
	cout<<s.top()<<" ";
	s.pop();
	}
	cout<<endl;
}
void reverse(stack<int>&s,stack<int>tmp){
	if(tmp.empty()){
		return;
	}
	int x=tmp.top();
	tmp.pop();
	reverse(s,tmp);
	s.push(x);
}
int main(){
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	display(s);
	stack<int>tmp;
	while(!s.empty()){
		tmp.push(s.top());
		s.pop();
	}
	reverse(s,tmp);
	display(s);
	return 0;
}