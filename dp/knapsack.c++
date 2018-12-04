///find minimum number of coins;

#include <bits/stdc++.h>
using namespace std;

//int n;
int dp[100][100];//={0};
int fun(int p[], int w[], int ind, int wt){

	if(ind==0 || wt==0){
		dp[ind][wt]=0;
		return 0;
	}

	if(dp[ind][wt]!=0)
		return dp[ind][wt];
	int inc, exc;
	if(wt-w[ind-1]>=0)
	inc = p[ind-1]+fun(p,w,ind-1,wt-w[ind-1]);
	
	exc = 0 + fun(p,w,ind-1,wt);

	dp[ind][wt]=max(inc,exc);
	cout<<ind<<" "<<wt<<" "<<dp[ind][wt]<<endl;
	// cout<<endl;
	return dp[ind][wt];
}

int main(){

	int n,wt;
	cin>>n;
	int p[n+2];
	int w[n+2];
	for (int i = 0; i < n; ++i)
	{
		cin>>w[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	cin>>wt;

//	int dp[n+2][n+2]={0};
	int ans = fun(p,w,n,wt);
	//cout<<"\n";
	cout<<ans;
	return 0;
}