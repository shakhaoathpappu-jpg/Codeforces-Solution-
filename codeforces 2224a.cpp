#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        vector<long long>c(k);
        for(int i = 0; i < k; i++) cin >> c[i];
        long long m = 0;
        int c2 = 0;
        for(auto x : c){
            m = max(m, x);
            if(x >= 2) c2++;
        }
        bool ok = (m >= 3) || (c2 >= 2);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}