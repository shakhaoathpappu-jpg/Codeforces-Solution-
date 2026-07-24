#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int>a(n + 2);
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 2; i <= n - i + 1; i++) {
            int x = (a[i] == a[i - 1]) + (a[n - i + 1] == a[n - i + 2]);
            int y = (a[i] == a[n - i + 2]) + (a[n - i + 1] == a[i - 1]);
            ans += min(x, y);
        }
        if(n % 2 == 0) {
            if(a[n / 2] == a[n / 2 + 1]) ans++;
        }
        cout << ans << endl;
    }
}