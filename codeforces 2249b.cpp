#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+5;
ll n,m;
ll a[N];
int f0[N],f1[N];
ll aespa(int s){
	for(int i=0; i<=n ;i++){
		f0[i]=f1[i]=0;
	}
	for(int i=1; i<=n-1 ;i++){
		if(a[i]<1 || a[i]>=n) return 0;
	}
	for(int i=1; i<=s ;i++){
		if(i!=1 && a[i]<a[i-1]) return 0;
		if(i!=1 && a[i]==a[i-1]) f0[a[i]]++;
		else f1[a[i]]++;
	}
	for(int i=n-1; i>=s+1 ;i--){
		if(i!=n-1 && a[i]<a[i+1]) return 0;
		if(i!=n-1 && a[i]==a[i+1]) f0[a[i]]++;
		else f1[a[i]]++;
	}
	int cnt=0;
	ll res=1;
	for(int i=1; i<=n-1 ;i++){
		if(f1[i]>=2) return 0;
		if(f1[i]==0) ++cnt;
		else{
			for(int j=1; j<=f0[i] ;j++){
				res=res*cnt%mod;
				cnt--;
			}
		}
	}
	return res;
}
void solve(){
	cin >> n;
	int mxl=1,mxr=1;
	for(int i=1; i<=n-1 ;i++){
		cin >> a[i];
		if(a[mxl]<a[i]) mxl=i;
		if(a[mxr]<=a[i]) mxr=i; 
	}
	ll ways=0;
	ways+=aespa(mxl-1);
	ways+=aespa(mxr);
	ways%=mod;
	cout << ways << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
}