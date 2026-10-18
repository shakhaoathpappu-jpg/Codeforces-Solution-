#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int e = 0, o = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x < 1 || x > 1000000) {
                cout << -1 << endl;
                return 0;
            }
            if(x % 2 == 0) e++;
            else o++;
        }
        if((e == 0 && o == 3) || (e == 1 && o == 1)) cout << "Larpity" << endl;
        else cout << "Moggity" << endl;
    }
}