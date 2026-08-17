#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int a = 0;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            char c = toupper(s[0]);
            a |= (1 << (c - 'A'));
        }
        vector<string>s(m);
        vector<int>v(m, 0);
        vector<bool>f(m, false);

        for(int i = 0; i < m; i++) {
            cin >> s[i];
            for(char c : s[i]) v[i] |= (1 << (c - 'A'));
        }
        bool ok = true;
        int cnt = 0;
        while(ok){
            ok = false;
            for(int i = 0; i < m; i++) {
                if(f[i]) continue;
                if((v[i] & ~a) == 0) {
                    f[i] = true;
                    cnt++;
                    a |= (1 << (s[i][0] - 'A'));
                    ok = true;
                }
            }
        }
        if(cnt == m) cout << "YES\n";
        else cout << "NO\n";
    }
}