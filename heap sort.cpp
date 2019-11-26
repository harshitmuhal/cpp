#include <iostream>
using namespace std;
void heapify(int arr[],int n,int idx){
    int minidx=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(arr[minidx]>arr[left] && left<n){
        minidx=left;
    }
    if(arr[minidx]>arr[right]&& right<n){
        minidx=right;
    }
    if(idx!=minidx){
        swap(arr[idx],arr[minidx]);
        heapify(arr,n, minidx);
    }
}
void heap_sort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        heapify(arr, n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr, i,0);
    }
}
int main()
{
    int arr[]={7,2,9,1,4,3,6};
    int n=7;
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
return 0;
}

