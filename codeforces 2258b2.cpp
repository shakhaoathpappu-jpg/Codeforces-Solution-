#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll a[N];

int main() 
{
    int t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vector<ll> c(m + 2), s(m + 3);
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            c[a[i]]++;
            sum += a[i];
        }
        for(int i = m; i >= 1; i--)
            s[i] = s[i + 1] + c[i];

        vector<ll> ans(m + 1, sum);
        ll p = 2;
        for(ll k = 1; p <= m; k++, p *= 2) {
            ll mx = 0;
            ll lim = p - 1;
            for(ll len = 1; len <= m; len++) {
                ll cur = 0;
                ll x = min(lim, m / len);

                for(ll j = 1; j <= x; j++)
                    cur += s[j * len];

                if(p * len <= m)
                    cur += c[p * len];

                mx = max(mx, cur);
            }
            ans[k] = mx;
        }

        for(ll k = 1; k <= m; k++) cout << ans[k] << " \n";
    }
}