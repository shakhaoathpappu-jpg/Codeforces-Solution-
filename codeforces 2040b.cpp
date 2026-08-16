#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x = 1, ans = 1;
        while(x < n){
            x = (x + 1) * 2;
            ans++;
        }
        cout << ans << endl;
    }
}