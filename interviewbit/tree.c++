#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}
};

int sum(node *root, int &ans){
	//cout<<"gggg";
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	int l = sum(root->left,ans);
	int r = sum(root->right,ans);

	ans = max(ans, l+r+root->data);
	return max(l,r)+root->data;

}
int maxDiameterSum(int n, int tree[]){
	vector< node* > v;
	node *nodet, *root = new node(tree[0]);
	int i=0;
	v.push_back(root);
	while(!v.empty()){
		nodet = v.front();
		v.erase(v.begin());
		if((2*i + 1)>=n)
			break;
		nodet->left=new node(tree[2*i+1]);
		v.push_back(nodet->left);

		if((2*i+2)>=n)
			break;
		nodet->right = new node(tree[2*i +2]);
		v.push_back(nodet->right);
		i++;
	}

	int ans = INT_MIN;
	sum(root,ans);
	return ans;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int tree[n+5];
		for (int i = 0; i < n; ++i)
		{
			cin>>tree[i];
		}

		int ans = maxDiameterSum(n,tree);
		cout<<ans<<"\n";
	}
	return 0;
}