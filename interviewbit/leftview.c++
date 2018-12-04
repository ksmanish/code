#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}
};
node *root =NULL;

void print(node *rot, int l, int &maxl){

	if(!rot)
		return;
	if(maxl < l){
		cout<<rot->data<<" ";
		maxl = l;
	}

	print(rot->right, l+1, maxl);
	print(rot->left, l+1, maxl);

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
	int maxl=0;
	print(rot,1,maxl);
}