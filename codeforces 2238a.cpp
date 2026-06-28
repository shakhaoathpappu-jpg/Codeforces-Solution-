#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<int>a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        long long r = LLONG_MAX, s = 0;
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(a[i]< b[i]) {
                ok = 0;
                break;
            }
            s += a[i] - b[i];
        }
        if(ok) r = min(r, s);
        vector<int>x =a, y=b;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ok = 1;
        s = c;
        for(int i = 0; i < n; i++) {
            if(x[i] < y[i]) {
                ok = 0;
                break;
            }
            s += x[i] - y[i];
        }
        if(ok) r = min(r, s);
        if(r == LLONG_MAX) cout << -1<<endl;
        else cout<< r<< endl;
    }
}