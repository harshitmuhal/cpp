#include <iostream>
#include<cstring>
using namespace std;


//top down approach
int k(int *v,int* wt,int n,int w,int *dp){
    int ans=0;
    if(w<=0){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(wt[i]<=w){
            if(dp[w-wt[i]]!=0){
                dp[w]=max(dp[w],v[i]+dp[w-wt[i]]);
            }
            else{
                dp[w]=max(dp[w],v[i]+k(v,wt,n,w-wt[i],dp));
            }
        }
    }
    return dp[w];
}

//bottom up approach
int unboundedKnapsack(int W, int n, int val[], int wt[]) 
{ 
    // dp[i] is going to store maximum value 
    // with knapsack capacity i. 
    int dp[W+1]; 
    memset(dp, 0, sizeof dp); 
  
    int ans = 0; 
  
    // Fill dp[] using above recursive formula 
    for (int i=0; i<=W; i++) 
      for (int j=0; j<n; j++) 
         if (wt[j] <= i) 
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]); 
  
    return dp[W]; 
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,w;
	    cin>>n>>w;
	    int v[n];int wt[n];
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>wt[i];
	    }
	    int dp[w+1];
	    memset(dp,0,sizeof(dp));
	    cout<<k(v,wt,n,w,dp)<<endl;
	}
	return 0;
}