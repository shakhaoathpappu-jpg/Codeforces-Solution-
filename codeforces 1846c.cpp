#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 205;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector <pair <ll, ll>> ans;
    for (int i = 0; i < n; ++i) {
        vector <int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        ll res = 0, tot = 0, cnt = 0;
        for (int j = 0; j < m; ++j) {
            res += a[j];
            if (res <= h) {
                tot += res, cnt++;
            } else {
                break;
            }
        }
        ans.emplace_back(cnt, -tot);
    }
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (ans[i] > ans[0]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}