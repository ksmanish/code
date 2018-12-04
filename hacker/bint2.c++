#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left=NULL, *right=NULL;

	node(int x): val(x), left(NULL), right(NULL){}
};

	node *temp=NULL;
int height(node *root){
	if(root==NULL)
		return 0;
	else{

		int lh = height(root->left);
		int rh= height(root->right);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}



void createbinarytree(node *root, int key){
	queue<struct node*>q;
	q.push(root);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		if(!temp->left){
			temp->left = new node(key);
			break;
		}
		else
			q.push(temp->left);
		if(!temp->right){
			temp->right = new node(key);
			break;
		}
		else
			q.push(temp->right);
	}

	
}
 int sum =0, c=0;
void levelorder(node *root, int pos, int level, int typ){
	//static int c=0;
	//static int sum =0;
	if(root==NULL){
		return;
	}
	if (level == 1){
		c++;
		//cout<<c<< " "<<root->val<<"\n";
		if(c==pos && typ==1)
			cout<<root->val<<"\n";
		sum +=root->val;
		//cout<<root->val<<" <-sum    ...  level-> "<<level<<"\n";
	} 
	else if(level>1){
		levelorder(root->left, pos, level-1,typ);
		levelorder(root->right, pos, level-1,typ);
	}
}

void levelorderr(node *root, int pos, int level, int typ, int value){
	//cout<<"hello "<<level<<"\n";
	//static int c=0;
	//static int sum =0;
	if(root==NULL){
		return;
	}
	if (level == 1){
		c++;
		//cout<<c<<" "<<root->val<<" \n";
		if(c==pos){
		//cout<<root->val<<"-----------***********\n";
			root->val = value;
			//cout<<root->val<<"-----------\n";
		}
		
	} 
	else if(level>1){
		levelorderr(root->left, pos, level-1,typ,value);
		levelorderr(root->right, pos, level-1,typ,value);
	}
}

void typ1(node *root, int pos, int level){
	c=0;
	levelorder(root,pos,level,1);
	
}

void typ2(node *root, int l, int r){
	sum=0;
	//int h = height(root);
	//cout<<h<<" height\n";
	for (int i = l; i <=r ; ++i)
	{
		levelorder(root,0,i,2);
		//cout<<sum<< i<<"----------------\n";
	}
	cout<<sum<<"\n";
}

/*void typ3(node *root, int pos, int level, int value){
	levelorderr(root,pos,level,3)
}
*/
int main(){
	int n,t,x,pos=1;
	cin>>n>>t;
	//queue<int>q;
	cin>>x;
	node *root = new node(x);
	for (int i = 0; i < n-1; ++i)
	{
		cin>>x;
		createbinarytree(root,x);
	}

	while(t--){
		int typ,levl,val,l,r,value;
		cin>>typ;
		if(typ==1)
		{
			cin>>pos>>levl;
			typ1(root,pos,levl);
		}

		else if (typ==2)
		{
			cin>>l>>r;
			typ2(root,l,r);
		}
		else if(typ==3){
			cin>>pos>>levl>>value;
			//cout<<"------------\n";
			c=0;
			levelorderr(root,pos,levl,3,value);
		}

	}
	
}