#include<iostream>
using namespace std;

void merge(long int arr[],long int s,long int e){
    long int temp[1000000];
    long int i=s;
    long int mid=(s+e)/2;
    long int j=mid+1;
    long int k=s;
    while(i<=mid&&j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {temp[k]=arr[j];
            k++;
            j++;}
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    
}

void mergesort(long int arr[],long int s,long int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}


int main() {
    long int n;
    cin>>n;
    long int arr[n];
    
    for(long int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    mergesort(arr, 0, n-1);
    for(long int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
