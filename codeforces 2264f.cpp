#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int mod = 1e9 + 7;
string s[200];
string u[51];

const int D = 60;

int main() {
    // int k ; cin >> k;
    // int ans = 1;
    // for(int i = 1;i <= k ;i++) ans = 1LL * ans * i % mod ;
    // int res = 0;
    // for(int i = 1;i <= 49;i++) {
    //     int d = 1;
    //     for(int j = k - 1 ; j >= k - i ; j--) d = 1LL * d * j % mod ;
    //     res = (res +d ) % mod ;
    // }
    s[1] = "n/n" ;
    s[2] = "(n+n)/n";
    s[3] = "(n+n+n)/n";

    for(int i= 4;i <= 199;i++) {
        s[i] = s[i - 1] + "+n/n" ;
        string t = "(";
        for(int j = 1 ; j < i ; j++) t += "n+";
        t += "n)/n";
        if(t.size() < s[i].size()) s[i] = t;

        for(int j = 1 ; j < i ; j++) {
            string t = s[j] + "+" + s[i - j] ;
            if(t.size() < s[i].size()) s[i]  =t;
        }
        for(int j = 2;j < i ; j ++) {
            if(i % j == 0) {
                string t = "(" + s[j] + ")*(" + s[i/j] + ")";
                if(t.size() < s[i].size()) s[i]  =t;
            }
        }
        // cerr << i <<' ' << s[i].size() << '\n' ;
        // cout << i <<' ' << s[i] << '\n' ;
    }
    string e = "(n/n)/(" + s[D] + ")+n/n";
    for(int i  =D - 1; i >= 1 ;i--) {
        e = "("  + e + ")/(" + s[i] + ")+n/n" ;
    }
    // cerr << e.size() << '\n';
    cerr << s[101].size() << '\n' ;
    
    string res = "n";
    for(int i = 1; i <= 49 ; i++) {
        res += "*(n/n+(n-(" + s[i + 1] + "))*round((n+" + s[50 - i] + ")/(" + s[101] + ")))" ;
    }
    res = "round((" + res + ")/(" + e +"))";
    cerr << res.size() << '\n' ;
    cout << res << '\n' ;
}