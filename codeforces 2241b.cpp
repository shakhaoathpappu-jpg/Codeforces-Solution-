#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin>> t;
    while(t--){
        string s; cin >>s;
        int n = s.length();
        long long y = 1;
        for(int i = 0; i < n; i++) y *= 10;
        y += 1;
        cout <<y<<endl;
    }
}