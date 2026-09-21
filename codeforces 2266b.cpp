#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        ll r = max(abs(a - b), a + c - b);
        cout << r << endl;
    }
}