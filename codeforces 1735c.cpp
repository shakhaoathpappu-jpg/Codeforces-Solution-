#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;cin >> t;
    while(t--) {
        int n; cin >> n;
        string t; cin >> t;
        vector<int> in(26, -1);  
        vector<int> out(26, -1);  
        int edges = 0;
        string ans;
        for(char c : t) {
            int x = c - 'a';
            if(in[x] != -1) {
                ans += char(in[x] + 'a');
                continue;
            }
            for(int y = 0; y < 26; y++) {
                if(out[y] != -1) continue;
                if(y == x) continue;
                bool cycle = false;
                int cur = x;
                while(out[cur] != -1) {
                    cur = out[cur];
                    if(cur == y) {
                        cycle = true;
                        break;
                    }
                }
                if(cycle && edges != 25) continue;
                in[x] = y;
                out[y] = x;
                edges++;
                ans += char(y + 'a');
                break;
            }
        }
        cout << ans << endl;
    }
}