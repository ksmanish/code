#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef pair<ll, ll> PL;
typedef tuple<ll, ll, ll> TL;

int main() {
    int n;
    cin>>n;
    int x,f=0;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x==1){
            f=1;
        }
    }
    if(f==0)
        cout<<"EASY";
    else
    cout<<"HARD";

    return 0;
}