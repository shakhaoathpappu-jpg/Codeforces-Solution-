#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vector<int>p(n, 0);
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) p[i] = p[i - 1] + 1;
            else p[i] = p[i - 1];
        }
        while(q--){
            int l, r, k; cin >> l >> r >> k;
            l--;
            r--;
            int x = p[r] - p[l];
            if(x <= 2 * k) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}