#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll,ll>
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mit(m) for(map<int, int > :: iterator it=m.begin();it!=m.end();++it)
#define mp make_pair
#define hell 1000000007
#define endl '\n'
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mint map<int,int> 
#define int long long
#define sll set<int>
#define pll pair<int,int>

void solve(){
	int n;
	cin>>n;
	if(n%3==0){
		cout<<1<<' '<<1<<' '<<n-2;
	}
	else if(n%3==1){
		cout<<1<<' '<<2<<' '<<n-3;
	}
	else{
		cout<<1<<' '<<2<<' '<<n-3;
	}
	
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

[close]
