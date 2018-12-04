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


void dfs(int a, vvll &v, std::vector<bool> &visited, vll &dist){
	visited[a]=true;
	dist[a]++;
	for(int i=0; i<v[a].size(); i++){
		if(!visited[v[a][i]]){
			dist[v[a][i]]=dist[a];
			dfs(v[a][i],v,visited,dist);
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
	std::vector<bool> visited(n+4,false);
    int a,b;
    vvll v(n+1);
    for(int i=1; i<n; i++){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);	
    }


    int q;
    cin>>q;
    vll ql;
    for (int i = 0; i < q; ++i)
    {
    	cin>>a;
    	ql.pb(a);
    }

    cout<<"jjjjjjjjjjjj\n";
    vll dist(n+1,0);
    dist[1]=-1;

    dfs(1,v,visited,dist);
    int c=0;
    sort(all(dist));
    int min=n+4,id;
    for(int i=0; i<q; i++){
    	if(dist[ql[i]]<min && visited[ql[i]]==true){
    		min=dist[ql[i]];
    		id=ql[i];
    	}
    }
    cout<<id;

	return 0;
	}