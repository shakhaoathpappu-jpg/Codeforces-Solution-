#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long>a(n + 1);
        a[1] = 501;

        for(int i = 2; i <= n; i++) {
            int x; cin >> x;
            a[i] = a[i - 1] + x;
        }
        for(int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }
}