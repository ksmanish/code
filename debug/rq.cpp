#include<bits/stdc++.h>
using namespace std;
long long int dp[1000005];
int main()
{
    int n;
    cin>>n;
   // cout<<n<<endl;
    vector<pair<int,int> >v;
    int s,q;
    for(int i=0;i<n;i++)
    { 
        cin>>s>>q;
       // cout<<s<<" "<<q<<endl;
        v.push_back(make_pair(q,s));
    }
    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
   int g=0;
  
  stack<pair<int,int> >st;
  
  
  //cout<<n<<"ttttttttttt"<<v.size()<<"\n";
  
    
  for(int i=0;i<n;i++)
  {
      //cout<<i<<"randi rona ";
      st.push(make_pair(v[i].first,v[i].second));
  }
  int y=st.top().first;
  cout<<"fhgbnm";
  /*while(!st.empty())
  {
      cout<<st.top().first<<" "<<st.top().second<<endl;
      st.pop();
  }*/
for(int i=1;i<=y;i++)
   {
       while( !st.empty() && st.top().second<i)
       {
           st.pop();
       }
       if(!st.empty())
       dp[i]=st.top().first;
       cout<<dp[i]<<" ";
   }

   cout<<"kkkkkkkkkkkkkkk\n";
    int f;
    cin>>f;
    long long int sum=0;
    for(int i=0;i<f;i++)
    {
        long long int k;
        cin>>k;
        long long int r=dp[k]/k;
        sum+=r*100;
    }
    cout<<sum<<endl;
    
      return 0;
}