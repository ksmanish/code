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

/*int bin(int rx, int ry, char cx, char cy, string s){
	int low=0, high = s.length()-1, mid,ans,temp;
	while(low<=high){
		mid = (low+high)/2;
		if(temp=chk(rx,ry,cx,cy,s)){
			ans =temp;

		}
	}
}*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int x,y;
    cin>>x>>y;
    int a=0,b=0;
    rep(i,0,n){
    	if(s[i]=='L')
    		a--;
    	else if(s[i]=='R')
    		a++;
    	else if(s[i]=='D')
    		b--;
    	else if(s[i]=='U')
    		b++;
    }


    cout<<a<<" "<<b<<"\n";
    int rx,ry;
    rx = a-x; ry = b-y;
    char cx, cy;
    if(a>x)
    	cx='R';
    else
    	cx='L';

    if(b>y)
    	cy='U';
    else
    	cy='D';

    cout<<cx<<" "<<cy<<"\n";
    //&& (abs(x)+abs(y))<n
    int pmax=-1, pmin=-1, f=0;

    if(rx==0 && ry==0)
    	cout<<0;
    else if(rx%2==0 && ry%2==0 ){
    	rx /=2; ry /=2;
    	int rxx = rx, ryy=ry;

    	//cout<<rx<<" "<<ry<<"\n";

    	//ans = bin(rx,ry,cx,cy,s);
    	int ans = INT_MAX;
    	rep(j,0,n){
    		rxx = rx, ryy=ry,f=0;
    		int accept=0;
    		if((rxx+ryy)<=n-j){
		    	rep(i,j,n){
		    		//cout<<"xxxxxxxxxxh\n";
		    		if(s[i]==cx && rxx!=0){
		    			if(f==0){
		    				rxx--;
		    				pmin=i+1;
		    				pmax = i+1;
		    				f=1;
		    			}
		    			else{
		    				rxx--;
		    				pmax = i+1;
		    			}
		    		}
		    		else if(s[i]==cy && ryy!=0){
		    			if(f==0){
		    				ryy--;
		    				pmax=i+1;
		    				pmin = i+1;
		    				f=1;
		    			}
		    			else{
		    				ryy--;
		    				pmax = i+1;
		    			}
		    		}

		    		if(rxx == 0 && ryy==0){
		    			accept=1;
		    			cout<<pmax-pmin+1<<"----------\n";
		    			break;
		    		}
		    	}
		    	if(accept)
		    	ans = min(ans,pmax-pmin+1);
			}


		}
			cout<<ans;

		    	/*repd(i,n-1,0){
		    		if(s[i]==cx && rx!=0){
		    			if(f==0){
		    				rx--;
		    				pmax=i+1;
		    				pmin = i+1;
		    				f=1;
		    			}
		    			else{
		    				rx--;
		    				pmin = i+1;
		    			}
		    		}
		    		else if(s[i]==cy && ry!=0){
		    			if(f==0){
		    				ry--;
		    				pmax=i+1;
		    				pmin = i+1;
		    				f=1;
		    			}
		    			else{
		    				ry--;
		    				pmin = i+1;
		    			}
		    		}

		    		if(rx == 0 && ry==0)
		    			break;
		    	}*/


    	/*int ans =0;
    	if(f==1)
    	ans = pmax-pmin +1;
    	//cout<<ans;
    	f=0;


    	int ans2=0;
    	if(f==1)
    		ans2 = pmax-pmin +1;
    	cout<<ans<<" "<<ans2<<"\n";
    	cout<<min(ans,ans2);
*/
    }

    else
    	cout<<"-1";


    


    
return 0;
}
