///find minimum number of coins;

#include <bits/stdc++.h>
using namespace std;

int fun(int coin[],int n, int dp[],int amount){
	if(amount==0)
		return 0;

	if(dp[amount]!=INT_MAX)
		return dp[amount];

	for (int i = 0; i < n; ++i)
	{
		

		if(amount-coin[i]>=0){
		
			int temp = fun(coin,n,dp,amount-coin[i]);
			
			if(temp+1<dp[amount]){
				dp[amount]=temp+1;
				
			}
		}
	}

	return dp[amount];
}

int funbottomup(int coin[],int n, int dp[],int amount){
	
	dp[0]=0;
	
	for (int i = 1; i <=amount; ++i)
	{
		for(int j=0; j<n; j++){
			if(i-coin[j]>=0){
				int temp = dp[i-coin[j]];
				if(temp+1<dp[i])
					dp[i]=temp+1;
			}

		}
	}

	return dp[amount];
}

int main(){


	int t;
	cin>>t;
	while(t--){
		int amount,n;
		cin>>amount>>n;
		int coin[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>coin[i];
		
		}


		int dp[amount+5];
		for (int i = 0; i < amount+2; ++i)
		{
			dp[i]=INT_MAX;
		}
		
		/*int ans = fun(n,dp,k);
		cout<<ans<<"\n";
*/
		 int ans = funbottomup(coin,n,dp,amount);
		cout<<ans<<"\n";
	}
	return 0;
}