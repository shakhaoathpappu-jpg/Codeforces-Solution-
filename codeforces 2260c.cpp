#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    int ans = x + y;
    cout << ans << ' ';
    if (!(~(x + y) & x)) {
        cout << 0 << '\n';
        return;
    }
    int k = 63 - __builtin_clzll(x & ~ans);
    int msk = (1LL << k) - 1;
    int z = (x & ~((1LL << (k + 1)) - 1)) | ((x + y) & msk);
    cout << x - z << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
}