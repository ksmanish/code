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
    ll n,r,c=0;
    cin>>n>>r;
    ll a[n];
    rep(i,0,n){
    	cin>>a[i];
    	if(a[i]==1)
    		c++;
    }

   ll p=0,req=0,cl=0,cr=0,rs=0,pp=0,f=0;
   rep(i,0,n){

   	if(a[i]==0){
   		if(cl<=r && cr<=r){			
	   		if(rs==0){
	   			cl++;
	   			if(p==1)
	   				cr++;
	   		}
	   		else{
	   			cr++;
	   			if(pp=1)
	   				cl++;
	   		}
   		}
   		else{
   			if(cl>r && p==1){
   				rs=1;
   				cl=0;
   				cr++;
   			}
   			if(cr>r && pp==1){
   				cl++;
   				cr=0;
   				pp=0;
   				rs=0;
   				req++;
   			}
   			else if((cl>r && p==0)|| (cr>r && pp==0)){
   				f=1;
   				break;
   			}

   		}


   	}

   	if(a[i]==1){

   		if(cl==r){
   			cl=0;
   			p=0;
   			rs=1;
   			cr=0;
   		}
   		if(cr==r){
   			cl=0;
   			cr=0;
   			rs=0;
   			p=0;
   			pp=0;
   			req++;
   		}
   		if(cl<r && rs==0){
   			p=1;
   			cl++;
   		}

   		if(cr<r && rs==1){
   			cr++;
   			pp=1;
   		}

   	}

   }

   if(f==1 || req>c)
   	cout<<"-1";
   else
   	cout<<req;

    
return 0;
}
