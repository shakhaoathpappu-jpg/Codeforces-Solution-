#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        if(k == n - 1){
            cout << -1 << endl;
            continue;
        }
        ll b = n-k;
        ll x =(b + 1) / 2;
        ll y = b / 2;
        ll p = (n + 1)/ 2;
        ll q = n /2;
        ll u = p-x;
        ll v = q- y;
        string s;
        for(ll i = 1; i <= b; i++) {
            char c;
            if(i % 2 == 1) c = '1';
            else c = '0';
            ll l = 1;
            if(i == 1) l += u;
            else if(i == 2) l += v;
            s.append(l, c);
        }
        cout << s << endl;
    }
}