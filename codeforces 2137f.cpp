#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) begin(x),end(x)
constexpr ll big = 1e18;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n),b(n);
        for (ll &i : a) cin >> i;
        for (ll &i : b) cin >> i;
        reverse(all(a));
        reverse(all(b));
        vector<ll> ok(n),ok1(n),ok2(n);
        vector<pair<ll,ll>> st;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll ans = 0, cur = 0;
        for (ll i = 0;i<n;i++) {
            ok[i] = (a[i]==b[i]);
            cur += ok[i]*(i+1);
            while (!st.empty()&&st.back().second<=a[i]) {
                ll j = st.back().first;
                ok1[j] = 1;
                if (ok2[j]&&!ok[j]) cur += j+1;
                st.pop_back();
            }
            /*for (ll j = i-1;j>=0;j--) {
                if (b[j]<=a[i]&&!ok2[j]) {
                    ok2[j] = 1;
                    if (ok1[j]&&!ok[j]) cur += j+1;
                }
            }*/
            while (!pq.empty()&&pq.top().first<=a[i]) {
                ll j = pq.top().second;
                pq.pop();
                ok2[j] = 1;
                if (ok1[j]&&!ok[j]) cur += j+1;
            }
            st.push_back({i,a[i]});
            pq.push({b[i],i});
            /*
            for (ll j = 0;j<=i;j++) {
                if (ok[j]||(ok1[j]&&ok2[j])) {
                    //cout << "i:" << i << " j:" << j << "\n";
                    //ans += j+1;
                }
            }
            */
            ans += cur;
        }
        cout << ans << endl;
    }
}