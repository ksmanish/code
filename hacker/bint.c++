#include <bits/stdc++.h>

using namespace std;

struct node{
	int data ;
	struct node *left, *right;
};

void findpar(int p, struct node **link, struct node *root){

	if(root->data==p){
		*link = root;
		return;
	}

	if(root==NULL)
		return;

	findpar(p,link, root->left);
	findpar(p,link, root->right);
}
void newnode(string s,int p, int d, struct node *root){

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL; 

	struct node *link =root;
	
	findpar(p, &link, link);
	cout<<link->data;	

	if(s[0]=='L')
		link->left=temp;
	else
		link->right=temp;

}

void print(struct node *root){
	if(root ==NULL)
		return;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int dist(struct node *root, int *height){
	int r=0,l=0,ld=0,rd=0;
	if(root==NULL){
		*height = 0;
		return 0;
	}
	ld =dist(root->left, &l);
	rd = dist(root->right, &r);

	*height = max(l,r)+1;
	return( max(l+r+1, max(ld,rd)));

}

bool comp(pair<int, pair<string, int> >  a, pair<int, pair<string, int> >  b){

	return (a.first<b.first);
}
int main(){
	struct node *root = NULL;
	root = (struct node*) malloc(sizeof(struct node));

	int t,d,p;
	cin>>t>>d;
	root->data = 1;
	root->left = NULL;
	root->right= NULL;
	string s;
	//vector < pair<int, pair<string, int> > > v;
	 int l;
	for(int i=0; i<t-1; ++i){
		cin>>p;
		cin>>d;
		cin>>s;
		//cout<<s<<"\n";
		//l =s.length();
		//v.push_back(make_pair(l,make_pair(s,d)));
		newnode(s,p,d,root);
	}
/*
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<t-1; ++i){
		
		newnode(v[i].second.first, v[i].second.second ,root);
	}

	int height =0; 
	int ans = dist(root, &height);

	cout<<ans;*/
	/*print(root);
	cout<<"\n";
	print(root);*/

}