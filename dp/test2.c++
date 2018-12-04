#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//vector<long long>fact(100000,-1);

long calcfact(int n,int l){
    long ans =1;
    for(int i=n; i>n-l; i--){
        ans *=i;
    }
    return ans;
}

// Complete the countTriplets function below.
long long countTriplets(vector<long long> &arr, long long r) {

   // cout<<"ooooooooooooooooooooooooooooooooooooooooo\n";
    int n= arr.size();
    map<long long,long long>m;
    long long max=-1;
   // cout<<"++++++++++++++++++++++++++++++++++++++\n";
    for(int i=0; i<n; i++){
        if(arr[i]>max)
            max=arr[i];
        m[arr[i]]++;
    }
   // cout<<"888888888888888888888888888888888888888888888888\n";
    set<long long>s(arr.begin(), arr.end());
    vector<long long>v(s.begin(), s.end());
    n=v.size();
   // cout<<"==============================================================="<<n<<"\n";
    long long count=0, temp,a,b,c;
    for(int i=0; i<n; i++){
        //cout<<i<<"\n";
        if((v[i]*r*r)>max)
            continue;
       if(r==1){
           
           a=m[v[i]];
           if(a<3)
            continue;
           
           if(a==3){
               count +=1;
               continue;
           }
           else if(a==4){
                count +=4;
           }
           else if(a==5){
               count +=60/6;
           }
           else if(a>=6){
               count +=(a*(a-1)*(a-2))/6;
           }
       }
       
       else{
            a=m[v[i]];
            b=m[v[i]*r];
            c=m[v[i]*r*r];
        
            count +=(a*b*c);
        //cout<<a<<" "<<b<<" "<<c<<" "<<count<<"\t"<<v[i]<<" "<<i<<"\n";
       }
    
    }
    return count;
}

int main()
{
    long long n,r;
    cin>>n>>r;
    vector<long long >arr(n);
    int i;
    for ( i = 0; i < n; ++i)
    {
        cin>>arr[i];
        //cout<<i<<"\n";
    }
    //cout<<"ppppppppppppppppppppppppppppppppppppp\n";
    long long ans = countTriplets(arr, r);
    cout<<ans;


    return 0;
}

