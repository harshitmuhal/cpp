#include<iostream>

using namespace std;

int multiply(int x,int array[],int size){
    int carry=0;
    for(int i=0;i<size;i++){
        int product=array[i]*x+carry;
        array[i]=product%10;
        carry=product/10;
    }
    
    while(carry){
        array[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}

void factorial(int n){
    int array[1000];
    //it means 1! is stored in array right now
    array[0]=1;
    int size=1;
    for(int x=2;x<=n;x++){
        size=multiply(x,array,size);
    }
    
    //to print array
    for(int i=size-1;i>=0;i--){
        cout<<array[i];
    }
}


int main(){
    int n;
    cin>>n;
    factorial(n);
    return 0;
}
