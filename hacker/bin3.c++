#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,c;
	cin>>n>>c;
	//vector<pair<int,int>>v;
	int a[n+5],b[n+5];
	a[1]=-1;
	for (int i = 2; i <=n ; ++i)
	{
		cin>>a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>b[i];
		//cout<<i<<" "<<b[i]<<"\n";
	}

	int index=0;
	for (int i = 1; i <=n ; ++i)
	{	
		index=0;
		for(int j=a[i]; j>=1; ){
			//cout<<b[i]<<" "<<b[j]<<" j= "<<j<<" i="<<i<<"\n";
			if(b[i]==b[j]){ 
				index = j;
				break;
			}

			j=a[j];
		}
		if(index!=0)
			cout<<index<<" ";
		else
			cout<<-1<<" ";
	}

	return 0;
}