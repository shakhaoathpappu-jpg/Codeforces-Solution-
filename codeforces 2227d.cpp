#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        int x = -1, y = -1;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                if (x == -1) x = i;
                else y = i;
            }
        }
        auto f = [&](int l, int r) {
            vector<bool> vis(n + 1, false);
            while (l >= 0 && r < 2 * n && a[l] == a[r]) {
                vis[a[l]] = true;
                l--;
                r++;
            }
            for (int i = 0; i <= n; i++) {
                if (!vis[i]) return i;
            }
            return n;
        };
        int ans = 1;
        ans = max(ans, f(x, x));
        ans = max(ans, f(y, y));
        ans = max(ans, f((x + y) / 2, (x + y + 1) / 2));
        cout << ans << '\n';
    }
}