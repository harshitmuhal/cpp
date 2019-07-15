#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}


void transfer(stack<int> &s,stack<int> &s2,int n){
    for(int i=0;i<n;i++){
        s2.push(s.top());
        s.pop();
    }
}

void reversestack(stack<int> &s){
    stack<int> s2;
    int n=s.size();
    for(int i=0;i<n;i++){
        int x=s.top();
        s.pop();
        transfer(s,s2,n-i-1);
        s.push(x);
        transfer(s2,s,n-i-1);
    }
}


int main() {
    stack<int> s;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        s.push(data);
    }
    
    reversestack(s);
    print(s);
    return 0;
}