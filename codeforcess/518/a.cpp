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

ll solve(){

    ll int n,m,k,l;
    cin>>n>>m>>k>>l;

    if(n<m){
    	return -1;
    	//cout<<"{{{{{{ \n";
    }
   
    else {
    	ll z = ceil((l+k)/(double)m);
    	cout<<z<<"--------\n";
    	if((m*z)<=n){
    			cout<<(m*z)<<" "<<n<<" [ "<<z<<"  =====\n";
    		if(((m*z)-k)>=l){
    			cout<<(m*z)-k<<" "<<l<<" [[[[[[[\n";
    			return z;
    		}
    		else 
    			return -1;
    	}
    	else{
    		//cout<<"jjjjjjjjj\n";
    		return -1;
    	}
    }
}

int main(){
	/*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    

    ll ans = solve();
    cout<<ans;


    
return 0;
}
