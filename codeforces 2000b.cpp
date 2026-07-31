#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> vis(n + 2, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        bool ok = true;
        vis[a[0]] = 1;

        for(int i = 1; i < n; i++) {
            int x = a[i];
            if (!vis[x - 1] && !vis[x + 1]) {
                ok = false;
                break;
            }
            vis[x] = 1;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}