#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=2e5+5;
int T,n,x,pos[N];

struct building{int m;vector<int>a,b;}p[N];

struct node{
	int mn,sum,r,id;
	bool operator <(const node &x)const{return mn>x.mn;}
};
priority_queue<node>q;
inline void add(int id){
	int sum=0,mn=0;
	for(int i=pos[id]+1;i<=p[id].m;i++){
		mn=max(mn,p[id].a[i]-sum);
		sum+=p[id].b[i]-p[id].a[i];
		if(sum>=0){q.push({mn,sum,i,id});return;}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n>>x;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			cin>>p[i].m;pos[i]=0;
			p[i].a.resize(p[i].m+2),p[i].b.resize(p[i].m+2);
			for(int j=1;j<=p[i].m;j++)cin>>p[i].a[j];
			for(int j=1;j<=p[i].m;j++)cin>>p[i].b[j];
		}
		for(int i=1;i<=n;i++)add(i);
		while(q.size()){
			auto t=q.top();if(t.mn>x)break;q.pop();
			x+=t.sum,pos[t.id]=t.r;add(t.id);
		}
		int ans=0,id=1;
		for(int i=1;i<=n;i++){
			int now=x,j=pos[i]+1;
			while(j<=p[i].m&&now>=p[i].a[j])now+=p[i].b[j]-p[i].a[j],j++;
			if(j-1>ans)ans=j-1,id=i;
		}
		cout<<ans<<' '<<id<<endl;
	}
}
