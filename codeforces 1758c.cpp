#include<bits/stdc++.h>
using namespace std;

int f(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return i;
    }
    return n;
}

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        if(n % x != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) a[i] = i;
        
        a[1] = x;
        a[n] = 1;
        int c = x;
        int l = n / x;
        while(l > 1) {
            int p = f(l);
            a[c] = c * p;
            c = c * p;
            l /= p;
        }
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}