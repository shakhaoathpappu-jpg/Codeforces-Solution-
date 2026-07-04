#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n;
        long long p; cin >> n >> p;
        vector<int> a(n), b(n);
        for(int &i : a) cin >> i;
        for(int &i : b) cin >> i;

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({b[i], a[i]});
        sort(v.begin(), v.end());
        long long s = p;
        int r = n - 1;
        for (auto [x, y] : v) {
            if (!r) break;
            if (x >= p) break;
            int z = min(y, r);
            s += 1LL * z * x;
            r -= z;
        }
        s += 1LL * r * p;
        cout << s <<endl;
    }
}