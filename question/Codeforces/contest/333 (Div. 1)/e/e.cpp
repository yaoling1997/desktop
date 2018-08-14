#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll mo= 1e9+7,pp= 1e7+19;
const int maxn= 2e4,maxq= 4e4;
struct query{
	int opt,x;
}M[maxq];
ll ans[maxq];
int v[maxn],w[maxn];
int s[maxq],stu[50][maxn],ex[50][maxn];
int f[100][2000];
int P[100];
int n,K,i,j,k,x,y,z,cnt,la,tot,q,Max;
void dfs(int o,int fa,int l,int r){
	if (l>r) return;
	int u= ++tot,&p= P[o],i,j;
	while (p<s[l]){
		if (M[p].opt==1) ex[o][M[p].x]= 1;
		else if (M[p].opt==2)
			ex[o][M[p].x]= 0;
		p++;		
	}
	memcpy(stu[u],ex[o],sizeof(ex[o]));
	while (p<=s[r]){
		if (M[p].opt==1) ex[o][M[p].x]= 1;
		else if (M[p].opt==2){
			ex[o][M[p].x]= 0;
			stu[u][M[p].x]= 0;
		}
		p++;
	}
	memcpy(f[u],f[fa],sizeof(f[u]));
	for (i= 1;i<=Max;i++)
		if (stu[u][i]&&!stu[fa][i])
			for (j= K;j>=w[i];j--)
				f[u][j]= max(f[u][j],f[u][j-w[i]]+v[i]);
	if (l<r){
		int mid= (l+r)>>1;
		dfs(o+1,u,l,mid);
		dfs(o+1,u,mid+1,r);
	}
	if (l==r){
		ll &x= ans[++la],y= 1;
		for (i= 1;i<=K;i++){
			x= (x+f[u][i]*y)%mo;
			y= y*pp%mo;
		}
	}
	tot--;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &K);
	Max= n;
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		v[i]= x;
		w[i]= y;
	}
	for (i= 1;i<=40;i++){
		for (j= 1;j<=n;j++)
			ex[i][j]= 1;
		P[i]= 1;
	}
	scanf("%d",&q);
	for (int qq= 1;qq<=q;qq++){
		scanf("%d",&x);
		if (x==1){
			Max++;
			scanf("%d%d",&y, &z);
			M[qq]= (query){x,Max};
			v[Max]= y;
			w[Max]= z;
		}else if (x==2){
			scanf("%d",&y);
			M[qq]= (query){x,y};
		}else {
			M[qq]= (query){x,0};
			s[++cnt]= qq;
		}
	}
	dfs(1,0,1,cnt);
	for (i= 1;i<=la;i++)
		printf("%I64d\n",ans[i]);	
	return 0;
}
