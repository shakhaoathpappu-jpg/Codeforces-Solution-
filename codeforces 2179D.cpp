#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>a;
        a.push_back((1 << n) - 1);
        a.push_back((1 << (n - 1)) - 1);

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < (1 << (n - 1 - i)); j++) {
                a.push_back((j << (i + 1)) | ((1 << i) - 1));
            }
        }
        for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << endl;
    }
}