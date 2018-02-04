#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 50010,mo= 10007,oo= 1e8;
int f[2][maxn],G[maxn],L[maxn],sl[maxn];
int n,m,i,j,k,cnt,x,l,r,ans,cur,pas;
void update(int &a,int b){
	a+= b;
	a-= a/mo*mo;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	m++;
	for (i= 1;i<=n;i++){
		scanf("%d",&L[i]);
		sl[i]= sl[i-1]+L[i];
		l= max(l,L[i]);
	}
	l--;r= oo;
	while (l+1<r){
		int mid= (l+r)>>1;
		cnt= 0;x= 0;
		for (i= 1;i<=n;i++)
			if (x+L[i]<=mid) x+= L[i];
			else cnt++,x= L[i];
		cnt++;
		if (cnt<=m) r= mid;
		else l= mid;
	}l= r;
	f[0][0]= 1;cur= 0;
	for (i= 1;i<=m;i++){
		pas= cur;cur^= 1;
		memset(f[cur],0,sizeof(f[cur]));
		G[0]= f[pas][0];
		for (j= 1;j<=n;j++)
			G[j]= G[j-1]+f[pas][j];
		k= 0;
		for (j= i;j<=n;j++){
			while (sl[j]-sl[k]>l) k++;
			update(f[cur][j],G[j-1]-G[k-1]);
		}update(ans,f[cur][n]);
	}
	printf("%d %d\n",l, ans);
	return 0;
}
