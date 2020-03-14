#include<iostream>
#include<vector>
using namespace std;

class heap{
    
    vector<int> v;
    //user shouldn't know that we are using vectors internally to build heap so make it private
    bool min_type;  //attribute to tell if heap is min heap or not
    
    bool compare(int a,int b){
        if(min_type){
            return a<b;
        }
        else{
            return a>b;
        }
    }
    
    void heapify(int idx){
        int left=idx<<1;
        int right=left+1;
        int min_idx=idx;
        int last_idx=v.size()-1;
        if(left<=last_idx && compare(v[left],v[idx])){
            min_idx=left;
        }
        if(right<=last_idx && compare(v[right],v[min_idx])){
            min_idx=right;
        }
        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }
    
public:
    
    heap(int n=10,bool heap_type=true){
        min_type=heap_type;
        v.reserve(n);
        v.push_back(-1);
        //block the first index
    }
    
    void push(int d){
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        
        while(idx>1&& compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    
    int get_top(){
        return v[1];
    }
    
    void pop(){
        int last_idx=v.size()-1;
        swap(v[last_idx],v[1]);
        v.pop_back();
        heapify(1);
    }
    
    bool empty(){
        
        return v.size()==1;
        //if v.size() is 1 then there is only -1 present in our vector which means no element has been added and it is empty
    }
};

istream& operator>>(istream &is,heap &h){
    int d;
    cin>>d;
    while(d!=-1){
        h.push(d);
        cin>>d;
    }
    
    return is;
}

void printheap(heap h){
    
    while(!h.empty()){
        cout<<h.get_top()<<" ";
        h.pop();
    }
    cout<<endl;
    
}

ostream& operator<<(ostream &os,heap h){
    printheap(h);
    return os;
}


int main(){
    heap h(13,false);
    cin>>h;
    
    printheap(h);
    return 0;
}