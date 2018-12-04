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
    string s;
    cin>>s;
    int a=0,b=0;
    for(int len=1; len<n; len++){

        int c=0,f=0;
        b=0,a=0;
        for(int i=0; i<n; i++){
            
            if(f==0){
                a+=s[i]-'0';
                c++;
                if(c==len){
                    if(a==0){
                        c=0;
                        continue;
                    }

                    f=1;

                }
            }
            else{
                if(a==b && (s[i]-'0')!=0)
                    b=0;
                b+=s[i]-'0';
                if(b>a)
                    break;
            }

        }
        if(a==b)
            break;

    }


    if(a==b)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
  