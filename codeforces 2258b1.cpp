#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll M = 1000000007;
int main()
{
    ll n1; cin>>n1;
    while(n1--){
        ll n,m; cin>>n>>m;
        vector<ll>a(n),b(m+2,0),c(m+2,0);
        for(int i = 0;i<n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        for(ll i = m;i>=1;i--){
            c[i] = c[i+1]+b[i];
        }
        ll d = 0;
        for(ll i = 1;i<=m;i++){
            ll e = c[i];
            if(2*i<=m){
                e += b[2*i];
            }
            if(e>d){
                d = e;
            }
        }
        cout<<d<<endl;
    }
}