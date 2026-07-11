#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> c(3, 0);
        for(int i = 0, x; i < n; i++) {
            cin >> x;
            c[x % 3]++;
        }
        int k = n/3;
        int ans = 0;
        for(int i = 0; i < 6; i++) {
            int x = i % 3;
            if (c[x] > k) {
                int d = c[x] - k;
                c[x] -= d;
                c[(x + 1) % 3] += d;
                ans += d;
            }
        }
        cout << ans << endl;
    }
}