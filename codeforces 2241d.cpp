#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin>> n;
        vector<long long>a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        long long x = 0, y = 0, z = 0;
        bool f = true;
        for(int i = 1; i <= n; i++) {
            long long d =(b[i] - a[i])* (i % 2 ? -1 : 1);
            long long c = d - z;
            if(i % 2) {
                y -= c;
                if(y < 0) f =false;
            }else{
                x += c;
                if(x < 0) f=false;
            }
            z=d;
            if(!f) break;
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}