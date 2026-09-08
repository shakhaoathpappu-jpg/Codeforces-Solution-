#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int z = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) z++;
        }
        int e = 0;
        if(a[0] == 0) e++;
        if(a[n-1] == 0) e++;
        
        int need = 2 - e;
        int av = z - e;
        if(av >= need) cout << need << endl;
        else cout << -1 << endl;
    }
}