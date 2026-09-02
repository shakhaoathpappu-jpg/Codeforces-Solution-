#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> add(vector<ll> v, ll x) {
    int pos = 0;
    while (pos < (int) v.size() && v[pos] >= x)
        pos++;
    v.insert(v.begin()+pos, x);
    return v;
}

vector<ll> solve(vector<tuple<ll,ll,int,bool>> v) {
    int n = (int) v.size();
    if (n == 1) {
        auto [l,r,c,del] = v[0];
        return {r-l+1};
    }

    vector<ll> inter(n-1);
    vector<ll> len(n);
    for (int i = 0; i < n-1; i++) {
        auto [l1,r1,c1,del1] = v[i];
        auto [l2,r2,c2,del2] = v[i+1];
        inter[i] = max(0LL, r1-l2+1);
        //cout << inter[i] << ' ';
    }

    for (int i = 0; i < n; i++) {
        auto [l,r,c,del] = v[i];
        len[i] = r-l+1;
        if (i)
            len[i]-= inter[i-1];
        if (i+1 < n)
            len[i]-= inter[i];
    }

    vector<ll> dp[2];
    dp[0] = {len[0]+inter[0]};
    dp[1] = {len[0]};

    for (int i = 1; i < n-1; i++) {
        vector<ll> nw[2];
        for (int d = 0; d < 2; d++) {
            for (int prv = 0; prv < 2; prv++) {
                ll x = len[i];
                if (prv)
                    x+= inter[i-1];
                if (!d)
                    x+= inter[i];
                vector<ll> cur = add(dp[prv], x);
                if (!prv || cur > nw[d])
                    nw[d] = cur;
            }
        }
        //cout << i << ' ' << nw[0][0] << ' ' << nw[1][0] << '\n';
        dp[0].swap(nw[0]);
        dp[1].swap(nw[1]);
    }

    vector<ll> ans;
    for (int prv = 0; prv < 2; prv++) {
        ll x = len.back();
        if (prv)
            x+= inter.back();
        vector<ll> cur = add(dp[prv], x);
        if (!prv || cur > ans)
            ans = cur;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        vector<tuple<ll,ll,int,bool>> a,b;
        for (int i = 0; i < n; i++) {
            ll l,r; cin >> l >> r;
            a.emplace_back(l,r,0,false);
        }
        for (int i = 0; i < m; i++) {
            ll l,r; cin >> l >> r;
            b.emplace_back(l,r,1,false);
        }

        int i = 0, j = 0;
        while (i < n && j < m) {
            auto [l1,r1,c1,del1] = a[i];
            auto [l2,r2,c2,del2] = b[j];
            if (max(l1,l2) <= min(r1,r2)) {
                if (l1 <= l2 && r2 <= r1)
                    get<3>(b[j]) = true;
                else if (l2 <= l1 && r1 <= r2)
                    get<3>(a[i]) = true;
            }

            if (r1 < r2)
                i++;
            else if (r2 < r1)
                j++;
            else {
                i++;
                j++;
            }
        }

        vector<tuple<ll,ll,int,bool>> v;
        for (auto [l,r,c,del] : a)
            if (!del)
                v.emplace_back(l,r,c,false);
        for (auto [l,r,c,del] : b)
            if (!del)
                v.emplace_back(l,r,c,false);
        sort(v.begin(), v.end());
        vector<ll> ans;
        for (int l = 0; l < (int) v.size();) {
            int r = l+1;
            while (r < (int) v.size() && get<0>(v[r]) <= get<1>(v[r-1])+1)
                r++;
            vector<tuple<ll,ll,int,bool>> cur(v.begin()+l,v.begin()+r);
            vector<ll> res = solve(cur);
            //cout << l << ' ' << r << '\n';
            for (ll x : res)
                ans.push_back(x);
            l = r;
        }
        sort(ans.rbegin(), ans.rend());
        cout << ans.size() << '\n';
        for (ll x : ans)
            cout << x << ' ';
        cout << endl;
    }
}
