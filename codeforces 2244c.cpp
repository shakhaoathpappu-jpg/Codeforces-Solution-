#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int n, x, y; cin >> n >> x >> y;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int g = gcd(x, y);
        bool ok = true;
        for(int i = 0; i < n; i++){
            int j = a[i] - 1;
            if(i % g != j % g){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}