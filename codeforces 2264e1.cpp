#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 3005, mod = 998244353;
int n, a[N], f[N][N];
int pr[N], vis[N];

int main() 
{
    for(int i = 1; i < N; i++) pr[i] = 1;

    for(int i = 2; i < N; i++) {
        if(!vis[i]) {
            for(int j = i; j < N; j += i) {
                pr[j] *= i;
                vis[j] = 1;
            }
        }
    }
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) f[i][i] = i;

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(i % pr[j] == 0) f[i][j] = f[i - 1][j - 1];
                else f[i][j] = f[i][j - 1];
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + a[i]) % mod;
        }
        for(int i = 1; i <= n; i++) {
            ll c = 1;

            for(int j = i + 1; j <= n; j++) {
                ans = (ans + f[a[i]][a[j]] * c % mod) % mod;
                c = c * 2 % mod;
            }
        }
        cout << ans << endl;
    }
}