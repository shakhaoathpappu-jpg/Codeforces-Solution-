#include<bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, k;
        int64 m; cin >> n >> k >> m;
        if(m < k){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i++) {
            if(i == k) cout << (m - k + 1);
            else cout << 1;
            if(i != n) cout << ' ';
        }
        cout << endl;
    }
}