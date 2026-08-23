#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>>a(n + 1);
        for(int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ll ans = 0;
        
        vector<int> s(n + 1);
        auto dfs = [&](auto &&f, int x, int p) -> void {
            s[x] = 1;
            for(int y : a[x]) {
                if(y != p) {
                    f(f, y, x);
                    s[x] += s[y];
                }
            }
            ans++;
            if(s[x] >= k) ans += n - s[x];
            for(int y : a[x]) {
                if(y != p) {
                    int z = n - s[y];
                    if(z >= k)
                        ans += s[y];
                }
            }
        };
        dfs(dfs, 1, 0);
        cout << ans << endl;
    }
}