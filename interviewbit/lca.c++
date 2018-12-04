#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}
};
node *root =NULL;

node *lca(node *rot, int x, int y){
	if(!rot)
		return NULL;
	if(rot->data==x || rot->data==y)
		return rot;
	node *l_lca = lca(rot->left, x,y);
	node *r_lca = lca(rot->right,x,y);

	if(l_lca && r_lca)
		return rot;

	return (l_lca!=NULL)?l_lca:r_lca;
}

int formtree(int n, int arr[]){
	std::vector<node *> v;
	node *tree;
	root = new node(arr[0]);
	v.push_back(root);
	int i=0;
	while(!v.empty()){
		tree = v.front();
		v.erase(v.begin());
		if((i*2 +1)>=n){
			break;
		}
		else{
			tree->left=new node(arr[i*2+1]);
			v.push_back(tree->left);
		}

		if((i*2+2)>=n)
			break;
		else{
			tree->right=new node(arr[i*2+2]);
			v.push_back(tree->right);
		}
		i++;
	}

	
}

int main(){
	int n;
	cin>>n;
	//node *root =NULL;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
		formtree(n,arr);

	node *rot = root;
	
	int t;
	cin>>t;
	while(t--){
		
		int x,y;
		cin>>x>>y;
		node * ans = lca(rot,x,y);

		cout<<ans->data<<"\n";
	}
}