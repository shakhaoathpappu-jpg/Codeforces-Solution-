#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> p(n + 1);
        for(int i = 2; i <= n; i++) cin >> p[i];
        
        int m; cin >> m;
        vector<bool> d(n + 1, false);
        vector<bool> h(n + 1, false);
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            d[x] = true;
            h[x] = true;
        }
        vector<vector<int>> c(n + 1);
        for(int i = n; i >= 2; i--) {
            if(h[i]) {
                h[p[i]] = true;
                c[p[i]].push_back(i);
            }
        }
        vector<int> a;
        for(int i = 1; i <= n; i++) {
            if(d[i]) {
                for(auto x : c[i]) a.push_back(x);
            }
            else if(!c[i].empty()) {
                for(int j = 0; j + 1 < c[i].size(); j++)
                    a.push_back(c[i][j]);
            }
        }
        cout << a.size();
        for(auto x : a) cout << " " << x;
        cout << endl;
    }
}