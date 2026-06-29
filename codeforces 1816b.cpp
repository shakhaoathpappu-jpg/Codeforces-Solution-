#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++){
            if(i & 1){
                a[i] = 2 * n - i;
                b[i] = i;
            } else{
                a[i] = i;
                b[i] = 2 * n - i;
            }
        }
        b[n] = 2 * n;
        for(int i = 2; i < n; i++) {
            if(b[i] > a[i + 1]) {
                swap(b[i], a[i + 1]);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i > 1) cout << ' ';
            cout << a[i];
        }
        cout << endl;
        for(int i = 1; i <= n; i++) {
            if(i > 1) cout << ' ';
            cout << b[i];
        }
        cout << endl;
    }
}