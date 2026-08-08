#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>a(n);
        for(auto &x : a) cin >> x;
        vector<int>v, c;
        for(int i = 0; i < n; i++) {
            if(!v.empty() && v.back() == a[i]) c.back()++;
            else{
                v.push_back(a[i]);
                c.push_back(1);
            }
        }
        int g = v.size();
        ll ans;
        if(g == 1) ans = 1;
        else {
            ll x = g;
            bool f = false;
            for(int i = 0; i +1 < g; i++) {
                if(c[i] >= 2 && c[i+1] >= 2) {
                    f = true;
                    break;
                }
            }
            if(f) ans = x + 2;
            else{
                bool f2 = false;
                for(int i = 0; i < g && !f2; i++) {
                    if(c[i] >= 2) {
                        if(i + 1 < g) {
                            if(i + 2 >= g) f2 = true;
                            else if(v[i] != v[i + 2]) f2 = true;
                        }
                        if(!f2 && i-1 >= 0) {
                            if(i-2 < 0) f2 = true;
                            else if (v[i] != v[i - 2]) f2= true;
                        }
                    }
                }
                if(f2) ans =x + 1;
                else ans= x;
            }
        }
        cout<< ans<<endl;
    }
}