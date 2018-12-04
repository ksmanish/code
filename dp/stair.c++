///given no of steps nd no of jumps can take, find the max no ways to reach the top

#include <bits/stdc++.h>
using namespace std;

int fun(int n, int dp[],int k){


	if(n==1 || n==0){
		dp[n]=1;

		return dp[n];
	}
	
	if(dp[n]!=0)
		return dp[n];
	else{
		for (int i = 1; i <=k; ++i)
		{	
			if(n-i>=0)
			dp[n] += fun(n-i,dp,k);
			//cout<<n<<" "<<dp[n]<<" "<<n-i<<"\n";
		}
		
		return dp[n];
	}
}

int funbottomup(int n, int dp[], int k){
	dp[0]=1;
	dp[1]=1;
	for (int i = 2; i <=k ; ++i)
	{
		for (int j = 0; j <i ; ++j)
		{
			dp[i] +=dp[j];
			
		}
		
	}
	
	for (int i = k+1; i <=n; ++i)
	{
		dp[i]=2*dp[i-1]-dp[i-1-k];
	}
	return dp[n];
}

int main(){


	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int dp[n+5]={ };
		
		/*int ans = fun(n,dp,k);
		cout<<ans<<"\n";
*/
		 int ans = funbottomup(n,dp,k);
		cout<<ans<<"\n";
	}
	return 0;
}