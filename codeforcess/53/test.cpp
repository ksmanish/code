#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define eps 1e-10
#define INF 0x3f3f3f3f3f3f3ff3
#define N 200100
#define M
using namespace std;

ll n,num[N],pos[N],ans=N,x,y;
char str[N];

int main()
{
	ll i,j,k,mx,l,r,p,q;
	cin>>n;
	scanf("%s",str+1);
	cin>>x>>y;
	if(abs(x)+abs(y)>n || (abs(x)+abs(y))%2!=n%2)
	{
		puts("-1");
		return 0;
	}
	p=q=0;
	for(i=1; i<=n; i++)
	{
		if(str[i]=='R') p++;
		else if(str[i]=='L') p--;
		else if(str[i]=='U') q++;
		else if(str[i]=='D') q--;
	}

	cout<<p<<" "<<q<<"\n"
	for(l=1,r=0; l<=n; l++)
	{
		for(; r<=n&&r+1<l || (r-l+1)<abs(p-x)+abs(q-y)&&r<=n; r++)
		{
			if(str[r+1]=='R') p--;
			else if(str[r+1]=='L') p++;
			else if(str[r+1]=='U') q--;
			else if(str[r+1]=='D') q++;
		}
		if((r-l+1)>=abs(p-x)+abs(q-y)) ans=min(ans,r-l+1);//cout<<l<<" "<<r<<" "<<p<<' '<<q<<endl;
		if(str[l]=='R') p++;
		else if(str[l]=='L') p--;
		else if(str[l]=='U') q++;
		else if(str[l]=='D') q--;
		if(r)
		{
			if(str[r]=='R') p++;
			else if(str[r]=='L') p--;
			else if(str[r]=='U') q++;
			else if(str[r]=='D') q--;
			r--;
		}
		if(r)
		{
			if(str[r]=='R') p++;
			else if(str[r]=='L') p--;
			else if(str[r]=='U') q++;
			else if(str[r]=='D') q--;
			r--;
		}
	}
//	if(n==200000) while(1);
	cout<<ans;
}