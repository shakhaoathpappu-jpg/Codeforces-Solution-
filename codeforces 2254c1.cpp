#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int x = 0, y = 0, z = 0, w = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(a[i] == '1') x++;
                if(b[i] == '1') z++;
            } 
            else{
                if(a[i] == '1') y++;
                if(b[i] == '1') w++;
            }
        }
        if(x == z && y == w) cout << "YES\n";
        else cout << "NO\n";
    }
}