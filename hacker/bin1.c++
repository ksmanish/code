#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}

};
 
 node *temp = NULL;

void search(node *root, int p){
	if(root==NULL)
		return;
	else{
		 search(root->left,p);
		 if(root->data==p)
		 	temp =root;
		 search(root->right,p);
	}
}

int solution (node *root, node *moiroot, int val){
	if(root==NULL || moiroot ==NULL)
		return -1;

	if(root->data==val)
		return moiroot->data;
	else if(moiroot->data==val)
		return root->data;
	int ans = solution(root->left, moiroot->right, val);
	if(ans!=-1)
		return ans;
	return solution(root->right, moiroot->left, val);
}


int main(){
	int n,t;
	cin>>n>>t;
	char c;
	int p, data;
	node *root = new node(1);
	for (int i = 0; i < n-1; ++i)
	{
		cin>>p>>data>>c;
		search(root,p);
		if(c=='L')
			temp->left = new node(data);
		else
			temp->right = new node(data);
	}

	while(t--){
		cin>>p;
		data = solution(root, root, p);
		cout<<data<<"\n";
	}

	return 0;

}