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
//typedef tuple<int, int, int> T;
using namespace std;


void dfs(int a, vvll &v, std::vector<bool> &visited, char c[], map<char, int> &m){
	visited[a]=true;
	m[c[a]]++;
	for(int i=0; i<v[a].size(); i++){
		if(!visited[v[a][i]]){
			dfs(v[a][i],v,visited,c,m);
		}
	}
}



int main(int argc, char const *argv[])
{
	/* code */
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    char c[n+1];
    rep(i,1,n+1){
    	cin>>c[i];
    }

	//std::vector<bool> visited(n+4,false);
    int a,b;
    vvll v(n+1);
    mint num;
    cin>>a>>b;
    v[a].pb(b);
    num[a]=1;
    num[b]=1;
    for(int i=2; i<n; i++){
    	cin>>a>>b;
    	if(num[a]==1){
    		v[a].pb(b);
    		num[b]=1;
    	}
    	else{
    		v[b].pb(a);
    		num[a]=1;	
    	}
    }

    while(q--){
    	std::vector<bool> visited(n+4,false);
    	map< char, int> m;
    	map< char, int> mpp;
    	int x;
    	string s;
    	cin>>x>>s;
    	dfs(x,v,visited,c, m);
    	rep(j,0,s.length()){
    		mpp[s[j]]++;
    	}
    	int ans=0;
    	for(auto it: m){
    		cout<<it.first<<it.second<<" ";
    	}
    	cout<<"\n";
    	for(auto it : mpp){
    		
    			if(it.second>=m[it.first])
    			ans += it.second -m[it.first];


    		

    		//cout<<it.first<<" "<<it.second<<" "<<ans<<" \n";
    	}
    	cout<<ans<<"\n";
    }

    //cout<<"jjjjjjjjjjjj\n";
   

	return 0;
	}