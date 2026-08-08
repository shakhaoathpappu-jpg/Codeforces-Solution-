#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int>a(x), b(y);
        for(int &v : a) cin >> v;
        for(int &v : b) cin >> v;

        set<int>sa(a.begin(), a.end());
        set<int>sb(b.begin(), b.end());

        vector<int>v;
        for(int z : sa) v.push_back(z);
        for(int z : sb) {
            if(!sa.count(z)) v.push_back(z);
        }
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        int ca = 0, cb = 0, cnt = 0;
        int limit = n + m - 1;

        for(int z : v) {
            if(cnt == limit) break;
            bool ina = sa.count(z);
            bool inb = sb.count(z);
            if(ina && inb) {
                ans += z;
                cnt++;
            }else if (ina && ca < n) {
                ans += z;
                ca++;
                cnt++;
            } else if (inb && cb < m) {
                ans += z;
                cb++;
                cnt++;
            }
        }
        cout << ans << endl;
    }
}