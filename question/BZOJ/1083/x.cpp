#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 30001;
struct edge{
	int u,v,w;
};
edge a[maxn];
int f[maxn];
int n,m,i,x,y,z,cnt;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
bool cmp(edge a,edge b){return a.w<b.w;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		a[i]= (edge){x,y,z};
	}
	for (i= 1;i<=n;i++) f[i]= i;
	sort(a+1,a+m+1,cmp);
	for (i= 1;i<=m;i++){
		int u= a[i].u,v= a[i].v;
		if (find(u)!=find(v)){
			f[f[u]]= f[v];
			cnt++;
			if (cnt==n-1){
				printf("%d %d\n",n-1,a[i].w);
				return 0;
			}
		}
	}return 0;
}
