#include<iostream>
using namespace std;

bool canallot(int arr[],int mid,int n,int m){
    int sum=0,current_st =0;
    sum+=arr[0];
    if(sum<=mid){
        current_st++;
        if(current_st==m){
            return true;
        }
        sum+=arr[1];
    }
    return false;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int s=0,e=arr[n-1]-arr[0];
        int mid,ans;

        while(s<=e){
            mid=(s+e)/2;
            if(canallot(arr,mid,n,m)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
