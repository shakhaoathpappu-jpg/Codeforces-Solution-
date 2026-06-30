#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--){
        int n, r= 1, a;
        string s; cin >> n >> s;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i - 1]) r++;
        }
        if(r == 2) a =2;
        else a=1;
        cout <<a<<endl;
    }
}