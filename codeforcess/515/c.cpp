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
   
   int n;
   cin>>n;
   list<int>l;
   int x;
   char ch;
   
   rep(i,0,n){
   	cin>>ch;
   	cin>>x;
   	if(ch=='L'){
   		l.push_front(x);
   	}
   	else if(ch=='R'){
   		l.push_back(x);
   	}
   	else{
   		int s = l.size();
   		int k=0;
   		for(auto j : l){
   			//cout<<j<<" ";
   			if(j==x){
   				int ans =min(k,s-k-1);
   				cout<<ans<<"\n";
   				break;
   			}
   			k++;

   		}
   	}
   }
return 0;
}
