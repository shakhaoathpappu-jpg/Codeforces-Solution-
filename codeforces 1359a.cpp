#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int hand = n / k;
        int x = min(m, hand);

        int rem = m - x;
        int y = (rem + k - 2) / (k - 1);
        cout << x - y << "\n";
    }
}