#include<bits/stdc++.h>
using namespace std;

int main() 
{
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n), b;
    for(auto& x: a) cin >> x, x--;
    for(int i = 0; i < n; i++) {
      if(a[i] != i) b.emplace_back(i);
    }
    bool ok = 1;
    for(int j = 0; j+1 < (int)b.size(); j++) {
      ok &= a[b[j]] > a[b[j+1]];
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
