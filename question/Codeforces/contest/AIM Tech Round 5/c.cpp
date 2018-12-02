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
int a[maxn][6],ans[2];
int n,hp,hq,vp,vq;
bool solve(int o){
	int x=-1e9,xx=1e9,y=-1e9,yy=1e9;
	for (int i=1;i<=n;i++){
		if (i==o)
			continue;
		x=max(x,a[i][1]);
		xx=min(xx,a[i][3]);
		y=max(y,a[i][2]);
		yy=min(yy,a[i][4]);
	}
	ans[0]=x;
	ans[1]=y;
	return x<=xx&&y<=yy;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=4;j++)
			scanf("%d",a[i]+j);
		if (!hp||a[i][3]<a[hp][3])
			hp=i;
		if (!hq||a[i][1]>a[hq][1])
			hq=i;
		if (!vp||a[i][4]<a[vp][4])
			vp=i;
		if (!vq||a[i][2]>a[vq][2])
			vq=i;
	}
	if (a[hp][3]<a[hq][1]){
		if (!solve(hp))
			solve(hq);
	}else{
		if (!solve(vp))
			solve(vq);
	}
	printf("%d %d",ans[0],ans[1]);
	return 0;
}
