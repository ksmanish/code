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

    bool bin_helper(ll mid, vll &v, ll k){

    	ll c=1,n = v.size(),sum=0;
    	rep(i,0,n){
    		if(v[i]>mid)
    			return false;
    		else{
    			sum +=v[i];
    			if(sum>mid){
    				sum =0;c++;
    				sum=v[i];
    			}
    			if(c>k)
    				return false;

    		}
    	}

    	return true;
    }

    ll bin(ll low, ll high, vll &v, ll k){
    	ll mid, ans=0;
    	while(low<high){
    		mid =(low+high)/2;
    		if(bin_helper(mid,v,k)){
    			ans =mid;
    			high = mid -1;
    		}
    		else
    			low =mid+1;
    	}

    	return ans;
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
       	
       	ll k,t;
       	vll v;
       	ll x;
       	cin>>k;
       	t=1;
       	ll max=0, sum=0;
       	while(cin>>x){
       		v.pb(x);
       		sum +=x;
       		if(x>max)
       			max=x;
       	}

       	ll ans = bin(max,sum,v,k);

       	cout<<ans*t;
    return 0;
    }