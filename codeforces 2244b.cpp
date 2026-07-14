#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        long long s = 0;
        bool ok = true;
        for(int i = 0; i < n; i++){
            s+= a[i];
            long long k = i+1;
            long long x = k*(k + 1)/2;
            if (s < x) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}