/**Manish Kumar Singh ***/
// IIIT LUCKNOW
#include<bits/stdc++.h>
#define ll long long
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll,ll>
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mit(m) for(map<int, int > :: iterator it=m.begin();it!=m.end();++it)
#define mp make_pair
#define M 1000000007
#define endl '\n'
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mint map<int,int> 
#define sll set<int>
#define pll pair<int,int>

#define T tuple<int, int, int>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	ll f =0;
    	cin>>n;
    	ll a[n];
    	rep(i,0,n){
    		cin>>a[i];
    	}
    	map<ll, ll>m;
    	rep(i,0,n){
    		ll x = a[i]*a[i];
    		if(m[x]==1){
    			cout<<"Yes\n";
    			f=1;
    			break;
    		}
    		rep(j,i+1,n){
    			ll y = a[j]*a[j];
    			m[x+y]=1;
    		}
    	}
    	if(f==1)
    		continue;
    	rep(i,0,n){
    		ll x = a[i]*a[i];
    		if(m[x]==1)
    			cout<<"Yes\n";
    	}
    	cout<<"No\n";
    }



    
return 0;
}
