#include<bits/stdc++.h>
using namespace std;
typedef int int_;

int T,n,f,x;
string s;

int_ main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s;
		f=0;
		if(s[0]=='0'){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<s.size();i++){
			if(s[i]=='0'&&s[i-1]=='0'){
				f=1;
				cout<<"-1\n";
				break;
			}
		}
		if(f)continue;
		x=0;
		f=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='+'){
				if(x<0){
					f=0;
					break;
				}
				if(x==1)x=2;
				else x=1;
			}
			if(s[i]=='-'){
				if(x>0){
					f=0;
					break;
				}
				if(x==-1)x=-2;
				else x=-1;
			}
			if(s[i]=='0'){
				if(x==2||x==-2){
					f=0;
					break;
				}
				x=0;
			}
		}
		if(f){
			cout<<"1\n";
			continue;
		}
		f=1;
		for(int i=3;i<s.size();i++){
			if((s[i-3]=='+'&&s[i-2]=='-'&&s[i-1]=='-'&&s[i]=='+')||
			(s[i-3]=='-'&&s[i-2]=='+'&&s[i-1]=='+'&&s[i]=='-')){
				f=0;
				break;
			}
		}
		if(f)cout<<"2\n";
		else cout<<"3\n";
	}
}