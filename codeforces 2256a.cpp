#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t; cin >> t;
    while(t--){
        vector<ll>a(3); cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        ll x = a[0];
        ll y = a[1];
        ll z = a[2];

        ll ans = min(z - x, y);
        cout <<ans<<endl;
    }
}