#include<bits/stdc++.h>
using namespace std;

int main() 
{
  int T; cin >> T;
  while(T--) {
    int n, m; cin >> n >> m;
    vector<int>v(n);
    vector a(n, vector<int>(m));
    for(auto& x: v) cin >> x;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    auto check = [&] (int k) {
      int64_t s = 0;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = n-1; i >= 0; i--) {
        for (auto& x: a[i]) {
          pq.push(x);
          s += x;
          if((int)pq.size() > k) {
            s -= pq.top();
            pq.pop();
          }
        }
        if (s >= v[i]) return 1;
      }
      return 0;
    };

    int lo = 0, hi = m;
    while (hi-lo > 1) {
      int mid = (lo+hi)/2;
      if (check(mid)) hi = mid;
      else lo = mid;
    }
    cout << hi << endl;
  }
}
