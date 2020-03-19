#include<bits/stdc++.h>
using namespace std;
void display(stack<int>s){
	while(!s.empty()){
	cout<<s.top()<<" ";
	s.pop();
	}
	cout<<endl;
}
void insertatbottom(stack<int>&s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	insertatbottom(s,x);
	s.push(y);
}
void reverse(stack<int>&s){
	if(s.empty()){
		return;
	}
	int x=s.top();
	s.pop();
	reverse(s);
	insertatbottom(s,x);
}
int main(){
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	display(s);
	reverse(s);
	display(s);
	return 0;
}