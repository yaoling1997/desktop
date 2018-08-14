#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#include<string>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 200;
string s[maxn];
int per[maxn];
int n,ans;
bool cmp(int a,int b){
	return s[a].size()<s[b].size();
}
bool contains(string a,string b){
	int la=a.size(),lb=b.size();
	for (int i=0;i+lb-1<la;i++){
		bool bl=1;
		for (int j=0;j<lb;j++)
			if (a[i+j]!=b[j]){
				bl=0;
				break;
			}
		if (bl)
			return 1;
	}
	return 0;
}
int check(){
	for (int i=1;i<n;i++){
		if (!contains(s[per[i+1]],s[per[i]]))
			return 0;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		per[i]=i;
	}
	sort(per+1,per+n+1,cmp);
	ans=check();
	if (ans){
		cout<<"YES\n";
		for (int i=1;i<=n;i++)
			cout<<s[per[i]]<<endl;
	}else {
		cout<<"NO";
	}
	return 0;
}
