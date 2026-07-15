#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<long long> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<int> b(m);
        for(int i = 0; i < m; i++) cin >> b[i];
        
        sort(b.begin(), b.end());
        long long ans = 0, s = 0;
        for(int i = 1; i <= b[0]; i++) s += a[i];
        ans += abs(s);
        for(int i = 1; i < m; i++) {
            s = 0;
            for (int j = b[i - 1] + 1; j <= b[i]; j++) {
                s += a[j];
            }
            ans += abs(s);
        }

        s = 0;
        for(int i = b[m - 1] + 1; i <= n; i++) {
            s += a[i];
        }
        ans += s;
        cout << ans << endl;
    }
}