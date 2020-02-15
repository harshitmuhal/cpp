#include<bits/stdc++.h>

map<int,map<int,int>>dp;
map<int,map<int,int>>adj;

int tsp(int mask,int pos,int n){
	if(mask==((1<<n)-1)){
		return adj[pos][0];
	}
	if(dp.count(mask)!=0 and dp[mask].count(pos)!=0){
		return dp[mask][pos];
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		int newmask=1<<i;
		if((mask & newmask)==0){
			int newans=adj[pos][i]+tsp(mask | newmask,i,n);
			ans=min(ans,newans);
		}
	}
	dp[mask][pos]=ans;
	return ans;
}

int main(){	
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		n++;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					adj[i][j]=0;
				}
				else{
					int x;cin>>x;
					adj[i][j]=x;
				}
			}
		}
		dp.clear();
		cout<<tsp(1,0,n)<<endl;

	}
	return 0;
}