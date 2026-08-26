#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> f(ll n, vector<ll> a)
{
    vector<ll> ans(n), c(n + 2);
    set<ll> s;
    for(ll i = 0; i <= n + 1; i++) s.insert(i);
    
    for(ll x : a) {
        if(!c[x]) s.erase(x);
        c[x]++;
    }
    for(int i = 0; i < n; i++) {
        c[a[i]]--;

        if(!c[a[i]]) s.insert(a[i]);

        ans[i] = *s.begin();

        if(!c[a[i]]) s.erase(a[i]);
        c[a[i]]++;
    }

    return ans;
}

ll solve(vector<ll> a, ll n, ll k)
{
    if(k <= 5) {
        for(int i = 0; i < k; i++) a = f(n, a);
        ll s = 0;
        for(ll x : a) s += x;
        return s;
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(a[i] < i) {
            ll x = a[i];
            for(int j = 0; j < n; j++) {
                if(a[j] >= x)
                    a[j] = x + (k % 2);
            }
            break;
        }
        if(a[i] > i) {
            ll x = i ? a[i - 1] + 1 : 0;
            if(i == n - 1) {
                a[i] = x;
                break;
            }
            for(int j = 0; j < n; j++) {
                if(a[j] >= x)
                    a[j] = x + (k % 2 == 0);
            }
            break;
        }
    }
    ll s = 0;
    for(ll x : a) s += x;
    return s;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(ll &x : a) cin >> x;
        cout << solve(a, n, k) << endl;
    }
}