#include<bits/stdc++.h>
using namespace std;

int a[200000],b[200000];

int main()
{
	int T,n,i,f;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<n;i++)cin>>b[i];
		f=0;
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[i])f=1;
		}
		if(!f)
		{
			cout<<"0\n";
			continue;
		}
		f=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==1&&b[i]==0)f++;
		}
		if(f&1)
		{
			cout<<"1\n";
			continue;
		}
		f=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==1)f=1;
		}
		if(!f)
		{
			cout<<"-1\n";
			continue;
		}
		f=0;
		for(i=0;i<n;i++)
		{
			if(b[i]==0)f=1;
		}
		if(!f)
		{
			cout<<"-1\n";
			continue;
		}
		cout<<"2\n";
	}
}