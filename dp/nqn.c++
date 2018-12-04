#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<string> > &v, vector<vector<int> > &q, int A){
	std::vector<string> vec;
	string s="";
	for (int i = 0; i <A; ++i)
	{
		s="";
		for(int j=0; j<A; j++){
			if(q[i][j]==1){
				s +="Q";
			}
			else
				s +=".";
		}
		vec.push_back(s);
		/* code */
	}
	v.push_back(vec);
}


bool canplace(vector<vector<int> > &q, int A, int row, int col){

	
	for (int i = col; i>=0 ; i--)
	{
		if(q[row][i]!=0)
			return false;
	}
	for (int i = row, j =col; i >=0 && j>=0; i--, j--)
	{
		if(q[i][j]!=0)
			return false;
	}
	for (int i = row, j =col; i <A && j>=0; i++, j--)
	{
		if(q[i][j]!=0)
			return false;
	}
}


bool solvenqn(vector<vector<string> > &v, vector<vector<int> > &q, int A, int row, int col){
	if(col>=A){
		print(v,q,A);
		return true;
	}

	for (int i = 0; i < A; ++i)
	{
		if(canplace(q,A,i,col)){
			q[i][col]=1;
			solvenqn(v,q,A,row,col+1);
		}
		q[i][col]=0;

	}

	return false;
}

vector<vector<string> > solveNQueens(int A) {

	vector<vector<string> > v;
    vector<vector<int> > q(A, vector<int>(A,0));
    solvenqn(v,q,A,0,0);

    return v;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<string> > v;
	int A;
	cin>>A;
	v=solveNQueens(A);
	for (int i = 0; i < v.size(); ++i)
	{
		for(int j=0; j<A; j++){
			cout<<v[i][j]<<"\n";
		}
		cout<<"===============\n\n";
	}
	return 0;
}