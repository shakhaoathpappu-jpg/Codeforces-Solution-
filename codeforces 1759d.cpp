#include<bits/stdc++.h>
using namespace std;

int main() 
{
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    int z = n;
    int k = 1;
    
    while(z % 10 == 0) z /= 10;
    while(z % 5 == 0 && 2LL*k <= m) {
      k *= 2;
      z /= 5;
    }
    while(z % 2 == 0 && 5LL*k <= m) {
      k *= 5;
      z /= 2;
    }
    while(10LL*k <= m) k *= 10;
    k *= m/k;
    cout << 1LL*k*n << endl;
  }
}