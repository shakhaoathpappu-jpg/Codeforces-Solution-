#include<bits/stdc++.h>
using namespace std;
#define int long long

struct unit{
   int l, r, u, v;
};

void solve(){
   int n;
   cin >> n;
   vector<unit> a(n);
   for(int i = 0; i < n; ++i){
      cin >> a[i].l >> a[i].r >> a[i].u >> a[i].v;
   }
   for(int m = n; m >= 0; m--){
      if(m == 0){
         cout << "0\n";
         return;
      }
      int pos = 1;
      for(int i = 0;(i<n)&&(pos<=m); ++i){
         bool badl = ((pos>=a[i].l)&&(pos<=a[i].r));
         int rank = m-pos+1;
         bool badr = ((rank>=a[i].u)&&(rank<=a[i].v));
         if(!badl&&!badr){
            pos++;
         }
      }
      if(pos > m){
         cout << m << endl;
         return;
      }
   }
}

signed main() 
{
   int tt; cin >> tt;
   while (tt--) solve();
}
