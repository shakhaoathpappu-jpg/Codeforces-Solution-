#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    if (s.size() == 1) cout << 0 << endl;
    else {
        int cnt = 0;
        while(s.size() > 1){
            int sum = 0;
            for(char c : s) {
                sum += c - '0';
            }
            cnt++;
            s = to_string(sum);
        }
        cout << cnt << endl;
    }
}