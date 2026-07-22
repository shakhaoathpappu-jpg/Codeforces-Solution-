#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long>c;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (c.empty() || c.back() != x) c.push_back(x);
        }
        int m = c.size();
        if (m == 1) {
            cout << 1 << endl;
            continue;
        }
        int ans = 2;
        for (int i = 1; i + 1 < m; i++) {
            long long d1 = c[i] - c[i - 1];
            long long d2 = c[i + 1] - c[i];
            if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
                ans++;
        }
        cout << ans << endl;
    }
}
