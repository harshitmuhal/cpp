#include<iostream>
using namespace std;

void charfilter(int arr[],int i){
    int j=0;
    while(i>0){
        if(i&1){
            cout<<arr[j]<<" ";
        }
        i=i>>1;
        j++;
    }
    cout<<endl;
}

void printsubset(int arr[],int n){
    
    int total_subsets=(1<<n); //total subsets is equal to 2^n
    
    for(int i=0;i<total_subsets;i++){   //if you don't need empty subset start i from 1
        charfilter(arr,i);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    printsubset(arr,n);
    
    return 0;
}
