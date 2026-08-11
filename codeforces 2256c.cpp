#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n, m;
        string s; cin >> n >> m >> s;
        n *= 2;
        string r = s;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if(s[i] == '1' && s[j] == '0') {
                r[i] = '0';
                r[j] = '1';
            }
        }
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(r[i] == '1') {
                if(i & 1) x++;
                else y++;
            }
        }
        cout << x << " " << y << endl;
    }
}