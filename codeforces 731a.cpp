#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string s; cin >> s;
    char c = 'a';
    int ans = 0;

    for(char x : s) {
        int d = abs(x - c);
        ans += min(d, 26 - d);
        c = x;
    }
    cout << ans;
}