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
const int maxn= 5e3+10,maxm=2e4+10;
int h[maxn],des[maxm],nex[maxm];
int n,m,tot;
void add(int x,int y){
	nex[++tot]=h[x];
	des[tot]=y;
	h[x]=tot;
}
int getAns(int s){
	int re=0;
	for (int i=1;i<=n;i++){
		if (h[i]==0)
			continue;
		int c=n,cnt=0;
		for (int j=h[i];j;j=nex[j]){
			int v=des[j]-i;
			if (v<0)
				v+=n;
			cnt++;
			c=min(c,v);
		}
		int l=i-s;
		if (l<0)
			l+=n;
		int total=c+l+(cnt-1)*n;
		re=max(re,total);
	}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		add(x,y);
	}
	for (int i=1;i<=n;i++){
		int ans=getAns(i);
		printf("%d%c",ans,i<n?' ':'\n');
	}
	return 0;
}
