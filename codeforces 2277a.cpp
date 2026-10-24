#include<bits/stdc++.h>
#define int long long
using namespace std;

int cnt[110];
signed main()
{
	int T; cin>>T;
	while(T--){
		int n,k; cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x; cin>>x;
			cnt[x]++;
		}
		int res=0,ans=0;
		for(int i=0;i<=n;i++){
			res+=cnt[i];
			if(res>=k&&cnt[i]){
				res-=k;
				ans++;
			}else break;
		}
		cout<<ans<<endl;
		for(int i=0;i<=n;i++)cnt[i]=0;
	}
} 
