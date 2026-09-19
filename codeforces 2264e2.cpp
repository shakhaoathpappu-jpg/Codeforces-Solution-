#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 300000;
const ll M = 998244353;
const ll I = (M + 1) / 2;

vector<int> r(N + 1, 1);
vector<ll> p(N + 1, 1), q(N + 1, 1);

int main() 
{
    for(int i = 2; i <= N; i++) {
        if(r[i] == 1) {
            for(int j = i; j <= N; j += i) {
                r[j] *= i;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * 2 % M;
        q[i] = q[i - 1] * I % M;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> c(n + 1), d(n + 1);
        vector<ll> w(n + 1);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            c[x]++;
        }
        ll a = 0, s = 0;
        int f = 0;
        for(int y = 1; y <= n; y++) {
            int z = r[y];
            for(int x = z; x < y; x += z) {
                s += 1LL * (d[x - 1] - d[x]) * w[x];
                s %= M;

                if(s < 0) s += M;
                d[x] = d[x - 1];
            }
            ll v = (p[c[y]] - 1 + M) % M;
            a += v * p[f] % M * s;
            a += 1LL * y * v;
            a %= M;

            f += c[y];
            w[y] = v * q[f] % M;
            d[y] = y;
            s = (s + 1LL * y * w[y]) % M;
        }
        cout << a << endl;
    }
}