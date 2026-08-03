#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        s = ' ' + s;
        vector<int> l(n + 1), r(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        auto dfs = [&](auto self, int u) -> int {
            if (!u) return n;
            if (!l[u] and !r[u]) return 0;
            return min(self(self, l[u]) + (s[u] != 'L'), self(self, r[u]) + (s[u] != 'R'));
        };
        cout << dfs(dfs, 1) << endl;
    }
}