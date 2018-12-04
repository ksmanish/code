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

    
}

int main(){
	/*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int x;
    cin>>x;
    string s;
    cin>>s;
    
    int f=-1;
    for (int i = 0; i < x-1; ++i)
    {
        if(s[i]!=s[i+1]){
            f=i;
            break;
        }
    }
    if(f!=-1){
        cout<<"YES\n";
        cout<<s[f]<<s[f+1];
    }

    else
        cout<<"NO\n";

    


    
return 0;
}
