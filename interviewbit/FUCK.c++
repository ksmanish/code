#include <bits/stdc++.h>
using namespace std;



int main(){
	int n, q;
	cin>>n>>q;
	vector<int>v(n);
	vector<int>vv(n);
	vector<pair<int,int>>vp;
	vector<pair<int,int>>::iterator vpit;
	vpit =vp.begin();
	//map<int,int>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		vv[i]=v[i];
		vp.push_back(make_pair(v[i],i+1));
	}

	//cout<<m[5]<<"---\n";
	int k;
	vector<int>:: iterator it;
	vector<int>:: iterator beg;

	beg=vv.begin();
	int in=0;
	for (int i = 0; i < q; ++i)
	{
		//cout<<"ddd\n";
		if(v.size()>=q){
			k=q;
		}
		else 
			k=v.size();

		it = max_element(v.begin(), v.begin()+k);
		//cout<<"it "<<*it<<"\n";
		if(*it-i<=0){
			for(int j=0; j<k && j+i<q; j++){
				beg=vv.begin();
				vpit= vp.begin();
				in = find(vv.begin(),vv.end(),v[j])-beg;
				cout<<vp[in].second<<" ";
				vp.erase(vpit+in);
				vv.erase(beg+in);
			}
			break;
		}
		beg=vv.begin();
		vpit= vp.begin();
		in = find(vv.begin(), vv.end(),*it)-beg;
		cout<<vp[in].second<<" ";
		vp.erase(vpit+in);
		vv.erase(beg+in);
		v.erase(it);
		//add(v,q-1);

	}
}