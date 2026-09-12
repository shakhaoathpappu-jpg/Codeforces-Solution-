#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt += x;
        }
        int th = (n + 1) /2;
        if(cnt >= th) cout << "Bessie" << endl;
        else cout << "Elsie" << endl;
    }
}