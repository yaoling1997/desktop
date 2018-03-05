#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int c[maxn],f[maxn],g[maxn],t[maxn];
int n,m,ans,Max;
int find(int o){
	int re=0;
	while (o){
		re=max(re,t[o]);
		o-=o&-o;
	}
	return re;
}
void add(int o,int x){
	while (o<=Max){
		t[o]=max(t[o],x);
		o+=o&-o;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		c[x]++;
		c[y+1]--;
	}
	c[0]=1;
	for (int i=1;i<=m;i++){
		c[i]+=c[i-1];
		Max=max(c[i],Max);
	}
	Max+=10;
	for (int i=1;i<=m;i++){
		f[i]=find(c[i])+1;
		add(c[i],f[i]);
	}
	memset(t,0,sizeof(t));
	for (int i=m;i>0;i--){
		g[i]=find(c[i])+1;
		add(c[i],g[i]);
		ans=max(ans,f[i]+g[i]-1);
	}
	printf("%d",ans);
}
