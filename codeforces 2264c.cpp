#include<bits/stdc++.h>
using namespace std;
long long a[200000];
const long long mod=998244353;

int main()
{
	int T;
	long long n,i,c,s,lsum;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		sort(a,a+n,greater<long long>());
		c=1;
		s=0;
		lsum=a[0];
		for(i=1;i<n;i++)
		{
			s=(s*i+c*((lsum-a[i]*i)%mod))%mod;
			c=c*i%mod;
			lsum+=a[i];
		}
		cout<<s<<endl;
	}
}