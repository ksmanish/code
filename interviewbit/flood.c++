#include <bits/stdc++.h>
using namespace std;

int n,m;
void floodfill(int x, int y, int &p){
	//cout<<x<<" "<<y<<"\n";
	if(x>=n || x<0 || y>=m || y<0)
		return;

	if(x==m-1 && y==n-1){
		p++;
		return;
	}

	floodfill( x+1, y, p);
	//floodfill(v, x-1, y, k ,p);
	floodfill(x, y+1,p);
	//floodfill(v, x, y-1, k ,p);

	//return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		//vector<vector<int> > v(n, std::vector<int>(m));

		

		int x,y,k;
		x=0,y=0;
		int p= 0;

		floodfill(x,y,p);

		

		cout<<p<<"\n";

	}
}