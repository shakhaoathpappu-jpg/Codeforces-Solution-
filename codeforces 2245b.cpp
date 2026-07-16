#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n;
        long long c; cin >> n >> c;
        vector<long long>a(n);
        long long s = 0;
        for(int i = 0; i<n; i++) {
            cin >> a[i];
            s += a[i];
        }
        sort(a.begin(), a.end());
        long long ans = s - 1LL * n * c;
        int k = n/2;
        for(int i = 0; i < k; i++) {
            if(a[i] < c) ans += c - a[i];
            else break;
        }
        cout << ans << endl;
    }
}