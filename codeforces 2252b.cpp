#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int z = 0, o = 0;
        for(char c : s) {
            if (c == '0') z++;
            else o++;
        }
        vector<vector<int>> d(2, vector<int>(3, -1));
        for(char c : s) {
            int x = c - '0';
            int p = 1 - x;

            vector<vector<int>> nd = d;
            if (x == 0) nd[0][2] = max(nd[0][2], 1);
            else nd[1][0] = max(nd[1][0], 1);
            for(int i = 0; i < 3; i++) {
                if(d[p][i] != -1) {
                    int q = i - 1;
                    int r;
                    if (x == 0) r = q + 1;
                    else r = q - 1;
                    int j = r + 1;

                    if(j >= 0 && j < 3)
                        nd[x][j] = max(nd[x][j], d[p][i] + 1);
                }
            }
            d = move(nd);
        }
        int ans = 1e9;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                int l = d[i][j];
                if(l == -1) continue;
                int x = j - 1;
                int a = (l + x) / 2;
                int b = l - a;
                int p = z - a;
                int q = o - b;
                
                if(abs(p - q) <= 1) ans = min(ans, n - l);
            }
        }
        if(ans > n) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}