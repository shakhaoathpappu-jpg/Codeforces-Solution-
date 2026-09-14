#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s(n, '0');
        if(n == 1) s[0] = '1';
        else if(n == 2) s[0] = '1';
        else{
            int m = n + 1;
            if(m % 3 == 0 && (m / 3) % 2) {
                int x = (n - 2) / 6;
                s[0] = s[2*x + 1] = s[4*x + 1] = '1';
            }
            else {
                int y = m / 3;
                if(m % 3 && y % 2) y++;
                int x = (m - y) / 2;
                s[x - 1] = s[x + y - 1] = '1';
            }
        }
        cout << s << endl;
    }
}