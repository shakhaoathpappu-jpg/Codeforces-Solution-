#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> a(n), b;
        for(int &v : a) cin >> v;
        b = a;
        sort(b.begin(), b.end());
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(i < x && n - 1 - i < x){
                if (a[i] != b[i]){
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}