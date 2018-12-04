#include <bits/stdc++.h>

using namespace std;

bool chk(int mid,int clas,int student[],int cake){

int re=0;
	for (int i = 0; i < clas; ++i)
	{
		re += ceil(student[i]/(float)mid);
	}

	if(re<=cake)
		return true;
	else
		return false;
}

int bin(int student[], int cake, int clas,int max){
	int low = 0, high= max, mid,ans=-1;
	while(low<=high){
		mid =low+high;
		if(chk(mid,clas,student,cake)){
			high= mid-1;
			ans = mid;
		}
		else{
			low = mid+1;
			
		}
	}

	return ans;

}

int main(){
	int clas,cake;
	int student[clas+1];
	int max=0,total=0;

	cin>>clas>>cake;

	for (int i = 0; i < clas; ++i)
	{
		cin>>student[i];
		if(student[i]>max)
			max=student[i];
		total +=student[i];
	}

	if(clas>cake)
		cout<<"-1";

	if(clas==cake)
		cout<<max;

	int ans= bin(student,cake,clas,max);

	cout<<ans;
}