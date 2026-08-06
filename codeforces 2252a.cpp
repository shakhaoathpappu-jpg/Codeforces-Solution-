#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll>a(n);
        map<ll, int>m;
        ll s = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            m[a[i]]++;
        }
        ll f = 0, x = 0;
        for(auto p : m) {
            if(p.second > f) {
                f = p.second;
                x = p.first;
            }
        }
        if (f <= (n + 1) / 2) cout << s << endl;
        else{
            ll r = n - f;
            ll z = s - f * x;
            ll ans = z + (r + 2) * x;
            cout << ans << endl;
        }
    }
}