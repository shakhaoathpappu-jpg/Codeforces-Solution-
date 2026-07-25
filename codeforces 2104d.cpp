#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[400005];
int check[6000005],prime[500005],tot;
ll pre[500005];
void get(int n){
    for(int i=2;i<=n;i++){
        if(!check[i])prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++){
            check[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=tot;i++)pre[i]=pre[i-1]+prime[i];
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1,greater<ll>());
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    int pos=1;
    while(pos<n&&a[pos+1]>=pre[pos+1])pos++;
    printf("%d\n",n-pos);
}

int main()
{
    get(6e6);
    int _;scanf("%d",&_);
    while(_--)solve();
    return 0;
}