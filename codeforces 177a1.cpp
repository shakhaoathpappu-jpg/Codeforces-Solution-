#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+= a[i][(n-1)/2];
    }
    for(int i = 0; i < n; i++){
        sum+= a[i][i];
    }
    for(int i = 0; i < n; i++){
        sum+= a[(n-1)/2][i];
    }
    for(int i = 0, j = n-1; i < n; i++, j--){
        sum+= a[i][j];
    }
    sum -= (3* a[(n-1)/2][(n-1)/2] );
    cout << sum << endl;
}