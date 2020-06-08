#include<iostream>
using namespace std;

class myvector{
    
    int *arr;
    int size;
    int capacity;
    
    
public:
    myvector(int n=1){
        arr=new int[n];
        capacity=n;
        size=0;
    }
    
    myvector(myvector &v){
        arr= new int[v.capacity];
        size=v.size;
        capacity=v.capacity;
        for(int i=0;i<size;i++){
            arr[i]=v.arr[i];
        }
    }
    
    ~myvector()
    {
        if(arr!=NULL)
            delete []arr;
        cout<<endl<<"deleted object";
    }
    
    void push_back(int data){
        if(size==capacity){
            
            capacity=2*capacity;
            int *oldarr=arr;
            arr=new int[capacity];
            for(int i=0;i<size;i++){
                arr[i]=oldarr[i];
            }
            delete []oldarr;
        }
        arr[size]=data;
        size++;
    }
    
    void insert_at(int pos,int data){
        if(size==capacity){
            
            capacity=2*capacity;
            int *oldarr=arr;
            arr=new int[capacity];
            
            for(int i=0;i<pos;i++){
                arr[i]=oldarr[i];
            }
            for(int i=size-1;i>=pos;i--){
                arr[i+1]=oldarr[i];
            }
            arr[pos]=data;
            delete []oldarr;
        }
        else{
            for(int i=size-1;i>=pos;i--){
                arr[i+1]=arr[i];
            }
                arr[pos]=data;
            }
            size++;
    }
    
    void pop_back(){
        if(size>0)
        size--;
    }
    
    void pop_at(int pos){
        if(size>0 and pos<size){
            for(int i=pos;i<size;i++){
                arr[i]=arr[i+1];
            }
            size--;
        }
    }
    
    int size_myvector(){
        return size;
    }
    
    int capacity_myvector(){
        return capacity;
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    int& operator[](int i){
        return arr[i];
    }
    
    
};

ostream& operator<<(ostream &os,myvector v){
    v.print();
    return os;
}

istream& operator>>(istream &is,myvector &v){
    int n;
    cin>>n;
    int no;
    while(n--){
        cin>>no;
        v.push_back(no);
    }
    
    return is;
}

int main(){
    
    myvector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    v.push_back(4);
    v.print();
    cout<<endl;
    v.push_back(5);
    v.pop_at(2);
    v.print();
    cout<<endl;
    v.insert_at(2, 4);
    v.insert_at(2, 55);
    v.print();
    cout<<endl<<v[2]<<" "<<v[3]<<endl;
    
    myvector v2=v;
    cout<<v2;
    
    return 0;
}
