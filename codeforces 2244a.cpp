#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int m = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '#') c++;
            else c = 0;
            m = max(m, c);
        }
        int a = (m + 1) / 2;
        cout << a << endl;
    }
}