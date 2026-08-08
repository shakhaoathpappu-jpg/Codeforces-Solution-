#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<bool>p(N, true);

int main() 
{
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++) {
        if(p[i]) {
            for(int j = i * i; j < N; j += i)
                p[j] = false;
        }
    }
    int t; cin >> t;   
    while(t--){
        int n; cin >> n;
        if(p[n + 1]) cout << "YES\n";
        else cout << "NO\n";
    }
}