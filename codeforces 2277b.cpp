#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		int mi=1e9;
		for(int i=1;i<=n;i++){
			int x; cin>>x;
			mi=min(mi,x);
		}
		if(mi<n) cout<<n<<endl;
		else cout<<0<<endl;
	}
} 
