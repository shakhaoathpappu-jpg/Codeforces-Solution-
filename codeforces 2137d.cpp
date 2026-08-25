#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>a(n), c(n + 1), h(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]]++;
        }
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(c[i] % i) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        int d = 0;
        for(int i = 0; i < n; i++) 
        {
            if(c[a[i]]-- % a[i]) cout << h[a[i]] << " ";
            else cout << (h[a[i]] = ++d) << " ";
        }
        cout << endl;
    }
}