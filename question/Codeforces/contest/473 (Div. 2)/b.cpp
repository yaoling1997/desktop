#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5,oo=2e9;
map<string,int> M;
string s[maxn];
int c[maxn],a[maxn];
int n,k,m;
ll ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &k, &m);
	for (int i=1;i<=n;i++){
		cin>>s[i];		
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for (int i=1;i<=k;i++){
		int num;
		scanf("%d",&num);
		a[i]=oo;
		for (int j=1;j<=num;j++){
			int x;
			scanf("%d",&x);
			M[s[x]]=i;
			a[i]=min(a[i],c[x]);
		}
	}
	for (int i=1;i<=m;i++){
		string tmp;
		cin>>tmp;
		ans+=a[M[tmp]];
	}
	cout<<ans;
	return 0;
}
