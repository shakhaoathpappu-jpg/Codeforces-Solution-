#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<int> b(n + 1, 0), c(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(a[i] == 1) b[i] = b[i - 1] + 1;
            else b[i] = b[i - 1] - 1;
            
            if(a[i] == 1 || a[i] == 2) c[i] = c[i - 1] + 1;
            else c[i] = c[i - 1] - 1;
        }
        vector<int> s(n + 2, INT_MIN);
        for(int i = n - 1; i >= 1; i--) {
            s[i] = max(c[i], s[i + 1]);
        }
        bool ok = false;
        for(int i = 1; i <= n - 2; i++){
            if(b[i] >= 0) {
                if(s[i + 1] >= c[i]) {
                    ok = true;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}