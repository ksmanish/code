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

    int t;
    cin>>t;
    while(t--){

	    vll a;
	    ll n, temp;
	    vll lis;
	    cin>>n;
	    rep(i,0,n){
	    	cin>>temp;
	    	a.pb(temp);
	    	lis.pb(1);
	    }
	    ll max = lis[0];
	    rep(i,1,n){
	    	rep(j,0,i){
	    		if(a[j]<= a[i]){
	    			if(lis[j]+1>lis[i]){
	    				lis[i]=lis[j]+1;
	    				if(max<lis[i])
	    					max = lis[i];
	    			}
	    		}
	    	}
	    }

	    cout<<max<<"\n";
	}


    
return 0;
}
