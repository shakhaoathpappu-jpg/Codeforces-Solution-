#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        if(k < n || k > 2*n - 1) {
            cout << -1 << endl;
            continue;
        }
        int m = 2*n - k;
        vector<vector<int>>a(n, vector<int>(n, 0));
        for(int i = 0; i < m; i++) a[i][i] = i + 1;
        for(int i = m; i < n; i++) a[i][0] = i + 1;
        for(int j = m; j < n; j++) a[0][j] = n + (j - m + 1);

        int x = k + 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 0) a[i][j] = x++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j];
                if(j + 1 < n) cout << " ";
            }
            cout << endl;
        }
    }
}