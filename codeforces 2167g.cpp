#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), c(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> c[i];

        ll s = 0;
        for(int x : c) s += x;
        vector<ll>dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = c[i];

            for(int j = 0; j < i; j++) {
                if(a[i] >= a[j])
                    dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
        ll ans = s;
        for(int i = 0; i < n; i++) ans = min(ans, s - dp[i]);
        cout << ans << endl;
    }
}