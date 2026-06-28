#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >>t;
    while(t--){
        long long n; cin>> n;
        long long ans=0;
        for(long long b = 1; b <= n; b++) {
            long long cnt = n/b;
            ans += cnt * cnt;
        }
        cout << ans<<endl;
    }
}