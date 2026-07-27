#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long>a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(n % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        long long x = LLONG_MIN;
        long long y = LLONG_MAX;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) y = min(y, a[i]);
            else x = max(x, a[i]);
        }
        if(y - x >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}