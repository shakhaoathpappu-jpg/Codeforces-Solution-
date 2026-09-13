#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> diff(n+1,0);
        for(int k=1;k<=n;++k){
            ll c;
            cin>>c;
            ll l=c*k;
            if(l<n){
                int L=(int)l;
                int R=(int)min((ll)n-1,(c+1)*k-1);
                ++diff[L];
                --diff[R+1];
            }
        }
        vector<int> ans;
        int cur=0;
        for(int i=0;i<n;++i){
            cur+=diff[i];
            if(cur==0) ans.push_back(i);
        }
        cout<<ans.size()<<'\n';
        for(int x:ans) cout<<x<<' ';
        cout<<'\n';
    }
}