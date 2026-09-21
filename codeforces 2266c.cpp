#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int z = 0;
        for(char c : s) {
            if(c == '0') z++;
        }
        if(s[0] == '1') {
            cout << z << endl;
            continue;
        }
        int p = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                p = i + 1;
                break;
            }
        }
        if(p == -1) {
            cout << 0 << endl;
            continue;
        }
        int o = 0, zp = 0;
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '1') o++;
            else zp++;
            if(i >= p - 1) {
                int x = o + (z - zp);
                ans = min(ans, x);
            }
        }
        cout << ans << endl;
    }
}