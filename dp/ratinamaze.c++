#include<bits/stdc++.h>
using namespace std;

#define MAX 100

bool cango(int m[][MAX], int n, int posi, int posj){
	if(!(posi>=0 && posi<n && posj>=0 && posj<n))
		return false;
	if(m[posi][posj]==1)
		return true;
	return false;
}

//void print(string s)
bool solverat(vector<string> &v, int m[][MAX], int n, int posi, int posj, string s){
	if(posi==n-1 && posj==n-1){
		//print(v,m,n);
		v.push_back(s);
		return true;
	}
	//cout<<s<<" "<<posi<<" "<<posj<<"\n";

	if(cango(m,n,posi,posj+1)){
		s +="R";
		m[posi][posj+1]=-1;
		solverat(v,m,n,posi,posj+1,s);
		m[posi][posj+1]=1;
		s.pop_back();
	}
	if(cango(m,n,posi,posj-1)){
		s +="L";
		m[posi][posj-1]=-1;
		solverat(v,m,n,posi,posj-1,s);
		m[posi][posj-1]=1;
		s.pop_back();
	}
	if(cango(m,n,posi+1,posj)){
		s +="D";
		m[posi+1][posj]=-1;
		solverat(v,m,n,posi+1,posj,s);
		m[posi+1][posj]=1;
		s.pop_back();
	}
	if(cango(m,n,posi-1,posj)){
		s +="U";
		//cout<<posi-1<<" "<<posj<<"\n";
		m[posi-1][posj]=-1;
		solverat(v,m,n,posi-1,posj,s);
		m[posi-1][posj]=1;
		s.pop_back();
	}
	
	return false;
	

}


vector<string> printPath(int m[MAX][MAX], int n)
{
    std::vector<string> v;

    string s="";
    m[0][0]=-1;
    solverat(v,m,n,0,0,s);
    sort(v.begin(), v.end());
    return v;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[100][100];
		for (int i = 0; i < n; ++i)
		{
			for(int j=0; j<n; j++){
				cin>>m[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for(int j=0; j<n; j++)
				cout<<m[i][j]<<" ";
			cout<<"\n";
		}
		//m[0][0]=-1;
		printPath(m,n);
	}
	return 0;
}