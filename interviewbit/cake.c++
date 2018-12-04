#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
/*{
ll n,b;cin>>n>>b;
ll arr[n],ans=0;
for(ll i=0;i<n;i++){cin>>arr[i];ans=max(ans,arr[i]);}

if(n>b)cout<<"-1";
else if(n==b)cout<<ans;
else   // binary search to find minimum students/cake
{
    ll l=1,r=ans,mid;  // mid represents current number of students/cake
    while(l<r)
    {
        mid=(l+r)/2;
        ll ct=0;
        for(ll i=0;i<n;i++)
        {
            ct+=(arr[i]/mid);
            cout<<mid<<" =mid && ct=" <<ct<<" clas "<<arr[i]<<" "<<ceil(arr[i]/(float)mid)<<"\n";
        }

        if(ct<=b)
        {
            ans=min(ans,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    cout<<ans;*/
//}

    float f = 0.1;
    if(f==0.1)
        cout<<"uuuuuuuuu";
    else
        cout<<"ddddddd "<<f;

  return 0;
}