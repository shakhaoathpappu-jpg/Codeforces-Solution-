#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0, lo = n, hi = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                cnt++;
                lo = min(lo, i);
                hi = max(hi, i);
            }
        }
        if(cnt == 1) cout << 0 << endl;
        else if(cnt == 2) cout << 1 << endl;
        else cout << hi - lo << endl;
    }
}