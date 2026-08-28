#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<vector<int>> a(n + 1), b(n + 1);

        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            a[x].push_back(y);
            b[y].push_back(x);
        }

        vector<int> v(n + 1), in(n + 1);

        for(int i = 1; i <= n; i++)
            in[i] = b[i].size();

        int k = 1;
        queue<int> Q;

        for(int i = 1; i <= n; i++) {
            if(in[i] == 0) {
                v[i] = k++;
                Q.push(i);
            }
        }

        while(!Q.empty()) {
            int p = Q.front();
            Q.pop();

            for(int x : a[p]) {
                in[x]--;

                if(in[x] == 0) {
                    v[x] = k++;
                    Q.push(x);
                }
            }
        }
        vector<vector<int>> c(n + 1, {1, 1}), s(n + 1);
        for(int i = 1; i <= n; i++)
            s[i] = {(int)a[i].size(), (int)a[i].size()};

        vector<bool> r(n + 1, false);
        while(q--) {
            int ty, p; cin >> ty >> p;
            if(ty == 2) {
                if(c[p][0]) cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                r[p] = 1;

                if(c[p][0] == 0 && c[p][1] == 0)
                    continue;
                for(int x : b[p])
                    if(!r[x]) {
                        s[x][0] -= c[p][0];
                        s[x][1] -= c[p][1];
                    }

                c[p] = {0, 0};
                priority_queue<pair<int,int>> Q;
                for(int x : b[p])
                    if(!r[x])
                        Q.push({v[x], x});

                while(!Q.empty()) {
                    int p = Q.top().second;
                    Q.pop();
                    if(c[p][0] == (s[p][1] > 0) &&
                       c[p][1] == (s[p][0] == a[p].size()))
                        continue;
                    for(int x : b[p])
                        if(!r[x]) {
                            s[x][0] -= c[p][0];
                            s[x][1] -= c[p][1];
                        }
                    c[p][0] = (s[p][1] > 0);
                    c[p][1] = (s[p][0] == a[p].size());

                    for(int x : b[p])
                        if(!r[x]) {
                            s[x][0] += c[p][0];
                            s[x][1] += c[p][1];
                        }

                    for(int x : b[p])
                        if(!r[x])
                            Q.push({v[x], x});
                }
            }
        }
    }
}