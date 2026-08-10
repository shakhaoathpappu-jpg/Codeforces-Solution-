#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool a = 1, b = 1;
        bool c = 1, d = 1;

        for(int i = 0; i < n; i++) {
            if(s[i] == '?')  continue;
            if(i % 2 == 0) {
                int p = i / 2;

                if (s[i] != (p % 2 == 0 ? '0' : '1')) a=0;
                if(s[i] != (p % 2 == 0 ? '1' : '0'))  b= 0;
            } 
            else {
                int p = (i - 1) / 2;
                if(s[i] != (p % 2 == 0 ? '0' : '1')) c= 0;
                if(s[i] != (p % 2 == 0 ? '1' : '0')) d =0;
            }
        }
        cout << (a + b) * (c + d) << endl;
    }
}