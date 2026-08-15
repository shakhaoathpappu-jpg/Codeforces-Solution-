#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
    int t; cin>>t;
    while(t--){
        cin>>s;
        int n=s.length();
        bool f0=0, f1=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(f0) cout<<0;
                f0=1;
            }
            else{
                if(f1) cout<<1;
                f1=1;
            }
        }
        cout<<endl;
    }
}