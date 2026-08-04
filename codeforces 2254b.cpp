#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<char> c;
        vector<int> l;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && s[j] == s[i]) j++;
            c.push_back(s[i]);
            l.push_back(j - i);
            i = j;
        }
        int m = c.size();
        bool f = false;
        for(int i = 0; i < m; i++) {
            if(l[i] >= 2) {
                f = true;
                break;
            }
        }
        long long ans = LLONG_MAX;
        if(f) ans = min(ans, 1LL * m);
        for(int i = 1; i < m - 1; i++) {
            if(l[i] == 1) {
                long long x;
                if(c[i - 1] == c[i + 1]) x = m - 2;
                else x = m - 1;
                ans = min(ans, x);
            }
        }
        cout << ans << endl;
    }
}