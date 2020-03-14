#include <iostream>
#include<climits>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ans=max(ans,arr[i]);
        }
        
        //if maximum element is negative it means array has 0 positive elements
        if(ans<0){
            cout<<ans<<endl;
            continue;
        }
        
        //tabulation approach / bottom up approach
        int dp[n];
        if(arr[0]<0){
            dp[0]=0;
        }
        else{
            dp[0]=arr[0];
        }
        ans=dp[0];
        for(int i=1;i<n;i++){
            if(dp[i-1]+arr[i]<0){
                dp[i]=0;
            }else{
                dp[i]=dp[i-1]+arr[i];
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

