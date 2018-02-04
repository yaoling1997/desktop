#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
int f[maxn],g[maxn];
int n,m,bl,i,x,y,z,w;
int find(int o){
	if (o==f[o]) return f[o];
	int temp= f[o];
	f[o]= find(f[o]);
	g[o]+= g[temp];
	return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&w);
	for (int t= 1;t<=w;t++){
		scanf("%d %d\n",&n, &m);bl= 1;
		for (i= 0;i<=n;i++){
			f[i]= i;
			g[i]= 0;
		}
		for (i= 1;i<=m;i++){
			scanf("%d %d %d",&x, &y, &z);
			x--;
			find(x);
			find(y);
			if (f[x]!=f[y]){
				g[f[x]]= -z-g[x]+g[y];
				f[f[x]]= f[y];
			}else if(g[y]-g[x]!=z)
				bl= 0;
		}
		if (bl) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
