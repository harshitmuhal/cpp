question-
Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present
in the matrix or not.

code-

#include<iostream>
using namespace std;

bool staircase_search(int arr[100][100],int i,int j,int n,int m,int p){
    
    //base case
    if(i>=n and j<=0){
        return false;
    }
    if(arr[i][j]==p){
        return true;
    }
    
    //recursive case
    bool value;
    if(arr[i][j]<p){
        value=staircase_search(arr,i+1,j,n,m,p);
        return value;
    }
    else
        value=staircase_search(arr,i,j-1,n,m,p);
    return value;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int p;
        cin>>p;
        bool value=staircase_search(arr,0,m-1,n,m,p);
        if(value)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
