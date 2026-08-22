#include<bits/stdc++.h>
using namespace std;
#define int long long

void test_case() {
  int n,k, x; cin >> n >> k >> x;
  vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    
    auto okay = [&] (int mid) {
        vector<pair<int, int>> range;
        for (int i = 0; i < n; i++) {
            int L = a[i] - mid + 1;
            int R = a[i] + mid - 1;
            if (R < 0 || L > x) continue;
            L = max(L, 0LL);
            R = min(R, x);
            if (L <= R) range.emplace_back(L, R);
        }
        if (range.empty()) {
            return (int)k <= x + 1;
        }
        sort(range.begin(), range.end());
        int cnt = 0;
        int curL = range[0].first, curR = range[0].second;
        for (int i = 1; i < (int)range.size(); i++) {
            int L = range[i].first, R = range[i].second;
            if (L > curR + 1) {
                cnt += (curR - curL + 1);
                curL = L; curR = R;
            } else {
                curR = max(curR, R);
            }
        }
        cnt += (curR - curL + 1);
        int freecnt = (x + 1) - cnt;
        return freecnt >= k;
    };
    int l = 0, r = x + 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (okay(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }


    vector<pair<int, int>> forbidden;
    for (int i = 0; i < n; i++) {
        int L = a[i] - ans + 1;
        int R = a[i] + ans - 1;
        if (R < 0 || L > x) continue;
        L = max(L, 0LL);
        R = min(R, x);
        if (L <= R) forbidden.emplace_back(L, R);
    }
    sort(forbidden.begin(), forbidden.end());
    vector<int> mL, mR;
    for (auto &p : forbidden) {
        if (mL.empty() || p.first > mR.back() + 1) {
            mL.push_back(p.first);
            mR.push_back(p.second);
        } else {
            mR.back() = max(mR.back(), p.second);
            mL.back() = min(mL.back(), p.first);
        }
    }
    vector<int> result;
    int prev = 0;
    for (int i = 0; i < (int)mL.size(); i++) {
        for (int pos = prev; pos < mL[i] && (int)result.size() < k; pos++) {
            result.push_back(pos);
        }
        prev = mR[i] + 1;
    }
    for (int pos = prev; pos <= x && (int)result.size() < k; pos++) {
        result.push_back(pos);
    }
    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1; cin >> t;

  for(int cs = 1; cs <= t; cs++) {
    // cout << "Case " << cs << ": ";
    test_case();
  }

  return 0;
}