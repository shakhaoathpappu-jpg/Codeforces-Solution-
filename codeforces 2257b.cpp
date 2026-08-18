#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin>>t;
        while(t--){
            int n, m; cin >> n >> m;
            vector<long long> a(n), b(m);
            for(int i = 0; i < n; i++) cin >> a[i];
            for(int i = 0; i < m; i++) cin >> b[i];
            
            long long bh = a[0] + (n-1);
            long long vh = b[0] + (m-1);
            if(bh >= vh) cout << 1 << endl;
            else cout << 2 << endl;
        }
}