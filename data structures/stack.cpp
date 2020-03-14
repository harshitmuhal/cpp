#include <iostream>
#include<vector>
using namespace std;


template<typename t>
class stack{
    vector<t> v;
    
public:
    void push(int d){
        v.push_back(d);
    }
    
    void pop(){
        if(!v.empty())
        v.pop_back();
    }
    
    int top(){
        return *(v.end()-1); //or return v[v.size()-1];
    }
};

int main() {
    stack<int> s;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        s.push(data);
    }
    
    for(int i=0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
