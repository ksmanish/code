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
    ll n,m;
    cin>>n>>m;
    ll min,max;
    ll e = m;
    if(ceil((double)n/2)==m)
    	min=0;
    else if(ceil((double)n/2)>m){
    	min = n-2*m;
    	//cout<<"kkkkk\n";
    }
    else
    	min =0;

    //cout<<ceil(n/2)<<" "<<m<<"\n";

    if(n-1>m)
    	max=(n-1)-m;
    else if(n-1>=m){
    	rep(i,1,n+1){
    		e = i + (i*(i-3)/2);
    		if(e>m){
    			max = n-i;
    			break;
    		}
    	}
    }
    else max=0;
    cout<<min<<" "<<max;

    
return 0;
}
