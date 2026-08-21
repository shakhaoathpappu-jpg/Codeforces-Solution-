#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll g = 0;
        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            g = gcd(g, x);
        }
        ll x = 2;
        while(gcd(g, x) != 1) x++;
        cout << x << endl;
    }
}