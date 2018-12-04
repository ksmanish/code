#include<bits/stdc++.h>
using namespace std;
int main()
{
int a=10,b=0,c;
try //try block activates exception handling
{
if(b==0)
throw "Division by zero not possible";//throws exception
c=a/b;
}
catch(const char* ex)//catches exception
{
	cout<<"hellooooooooooo\n";
cout<<ex;
}

return 0;
}