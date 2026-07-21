#include<bits/stdc++.h>
using namespace std;

int ans;
vector<int> a;

void dfs(int l, int r, int b) {
    if (l == r) {
        ans = max(ans, 0);
        return;
    }
    int m = l + (1 << b);
    if(m > r) {
        dfs(l, r, b - 1);
        return;
    }
    int x = 0;
    for(int i = l; i < m; i++) x = max(x, a[i]);

    int y = 1000000032;
    for(int i = m; i <= r; i++) y = min(y, a[i]);
    if(x > y) ans = max(ans, 1 << b);
    dfs(l, m - 1, b - 1);
    dfs(m, r, b - 1);
}

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        a.assign(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        ans = 0;
        dfs(0, n - 1, __lg(n - 1));
        cout << ans << endl;
    }
}