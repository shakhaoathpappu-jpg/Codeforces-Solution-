#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    auto ask=[&](int u, int v, int d) {
        cout<<"? "<<u<<' '<<v<<' '<<d<<endl;
        int x;
        cin>>x;
        if(x==-1) {
            exit(0);
        }
        return x;
    };

    while(t--) {
        int n; cin>>n;
        int u=1, d=0;
        for(int v=2; v<=n; v++) {
            if(ask(1, v, d+1)) {
                u=v;
                d++;

                while(ask(1, v, d+1)) {
                    d++;
                }
            }
        }
        int first=d;
        int v=1;
        for(int x=2; x<=n; x++) {
            if(ask(u, x, d+1)) {
                v=x;
                d++;

                while(ask(u, x, d+1)) {
                    d++;
                }
            }
        }
        cout<<"! "<<u<<' '<<v<<' '<<d<<endl;
    }
}