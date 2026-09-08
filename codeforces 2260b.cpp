#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--){
        ll x, y, k; cin >> x >> y >> k;
        ll d = y - x;
        ll m = 0;
        if(d >= x){
            ll c = d - x + 1;
            m = min(k, c);
        }
        ll s = 0;
        for(ll i = 0; i < m; i++) {
            ll a = x + i;
            s += d % a;
        }
        ll r = k - m;
        s += d * r;
        cout << s << endl;
    }
}