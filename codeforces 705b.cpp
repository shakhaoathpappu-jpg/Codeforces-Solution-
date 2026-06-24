#include<iostream>
using namespace std;

int main() 
{
    int n; cin >> n;
    long long sum = 0;
    while(n--){
        int x; cin >> x;
        sum += x - 1;
        if(sum % 2 == 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
}