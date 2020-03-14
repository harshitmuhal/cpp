#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int dp[100][100];

int mincost(int *a,int i,int j){
    if(i==j){
        dp[i][j]=0;
        return 0;
    }
   if(dp[i][j]!=-1){
       return dp[i][j];
   }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=mincost(a,i,k)+mincost(a,k+1,j)+a[i-1]*a[k]*a[j];
        ans=min(temp,ans);
    }
    dp[i][j]=ans;
    return ans;
}

int main(){
    //if array a has size n then no of matrix =n-1
    //in the below example a has data for 3 matrix
    //matrix 1- order: a[0]xa[1]
    //matrix 2- order: a[1]xa[2]
    //matrix 3- order: a[2]xa[3]
    int a[]={1,2,3,4};
    memset(dp,-1,sizeof(dp));
    mincost(a,1,3);              //i,j is ith and jth matrix so we pass starting and ending matrix no
    cout<<dp[1][3]<<endl;       // i.e 1 i.e first matrix and 3 i.e 3rd matrix
    return 0;
}
