#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() 
{
    ll S;
    int q; cin >> S >> q;
    vector<ll> d;
    for (ll x = 1; x * x <= S; x++) {
        if (S % x == 0) {
            d.push_back(x);

            if (x * x != S)
                d.push_back(S / x);
        }
    }
    sort(d.begin(), d.end());
    int m = d.size();
    vector<ll> l(m + 1), v(m + 1), pl(m + 1), ps(m + 1);

    for(int i = 1; i <= m; i++) {
        l[i] = (i == 1 ? 1 : d[i - 2] + 1);
        v[i] = S / d[i - 1];

        ll len = d[i - 1] - l[i] + 1;

        pl[i] = pl[i - 1] + len;
        ps[i] = ps[i - 1] + v[i] * len;
    }
    auto sum = [&](ll x) -> ll {
        if (x <= 0)
            return 0;

        int lo = 1, hi = m, p = m;

        while (lo <= hi) {
            int md = (lo + hi) / 2;

            if (l[md] <= x) {
                p = md;
                lo = md + 1;
            } else {
                hi = md - 1;
            }
        }

        return ps[p - 1] + v[p] * (x - l[p] + 1);
    };

    while (q--) {
        ll x, y;
        cin >> x >> y;

        if (y >= S) {
            cout << sum(x) << '\n';
            continue;
        }

        int lo = 1, hi = m, id = m + 1;

        while (lo <= hi) {
            int md = (lo + hi) / 2;

            if (v[md] < y) {
                id = md;
                hi = md - 1;
            } else {
                lo = md + 1;
            }
        }
        ll z = min(x, pl[id - 1]);
        ll ans = y * z + sum(x) - sum(z);
        cout << ans << endl;
    }
}

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}