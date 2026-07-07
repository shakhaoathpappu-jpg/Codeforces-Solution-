#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n;
        long long k; cin >> n >> k;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        vector<long long> f(n + 2, 0);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            int l = j - i;
            f[l]++;
            i = j;
        }
        vector<long long> c(n + 2, 0), s(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            c[i] = c[i + 1] + f[i];
            s[i] = s[i + 1] + 1LL * i * f[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] > 0) {
                long long x = c[i];
                long long y = s[i];
                long long d = k - y;
                if(d % x == 0) {
                    long long z = d / x;
                    if (z >= 1 - i) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}