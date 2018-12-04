#include <bits/stdc++.h>
using namespace std;

int fun(int n, int dp[]){

	if(n==1 || n==0){
		dp[n]=n;

		return n;
	}
	
	if(dp[n]!=0)
		return dp[n];
	else{

		dp[n] = fun(n-1,dp)+fun(n-2,dp);
		return dp[n];
	}
}


int main(){


	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dp[n+5]={ };
		//cout<<dp[1]<<"============\n";
		int ans = fun(n,dp);
		cout<<ans<<"\n";
	}
	return 0;
}