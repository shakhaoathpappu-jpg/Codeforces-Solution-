#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    static long long a[200005];
    static long long b[200005];

    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);

        int f = 1;
        if(n < 2 * m) f = 0;
        for(int i = 0; i < m && f; i++) {
            if(a[i] > b[i] || a[n - m + i] < b[i]) f = 0;
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}