#include<bits/stdc++.h>
using namespace std;

#define int long long
int a[200005];

signed main() 
{
    int t; cin>> t;
    while(t--){
        int n, k; cin >> n >> k;
        int z = 0, o = 0, tw = 0;
        for(int i = 0; i < k; i++) {
            char c; cin >> c;
            if (c == '0') z++;
            else if (c == '1') o++;
            else tw++;
        }
        if(n == k) {
            for (int i = 0; i < n; i++) cout << '-';
            cout << '\n';
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(i <= z || n - i + 1 <= o) a[i] = -1;
            else if(z + tw < i && i <= n - o - tw) a[i] = 1;
            else a[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) cout << '-';
            else if (a[i] == 1) cout << '+';
            else cout << '?';
        }
        cout << endl;
    }
}