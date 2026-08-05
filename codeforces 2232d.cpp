#include<bits/stdc++.h>
using namespace std;

struct M {
    int a, b, c;
};

int a[25];
vector<M> v;

void f(int n, int s, int t, int x) {
    if(n == 0) return;

    if(a[n] == 0) {
        f(n - 1, s, x, t);
        v.push_back({n, s, t});
        f(n - 1, x, t, s);
    } 
    else{
        int m = n - 1 - a[n];
        f(m, s, x, t);
        v.push_back({n, s, t});
        f(m, x, s, t);
        f(n - 1, s, t, x);
    }
}

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] > i - 1) ok = false;
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        v.clear();
        f(n, 1, 3, 2);
        cout << "YES\n";
        cout << v.size() << '\n';

        for(auto x : v)
            cout << x.a << " " << x.b << " " << x.c << '\n';
    }
}