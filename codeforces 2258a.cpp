#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        cout << (n == 1 ? a[0] : __gcd(a[0], a[n - 1])) << endl;
    }
}