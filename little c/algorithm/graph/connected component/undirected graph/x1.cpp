#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
int f[maxn],b[maxn],d[maxn];
int n,m,i,top,x,y;
int find(int o){
	if (o==f[o]) return f[o];
	f[o]= find(f[o]);
	return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		f[x]= find(f[x]);f[y]= find(f[y]);
		f[f[x]]= f[y];
	}
	for (i= 1;i<=n;i++){
		f[i]= find(f[i]);
		if (!b[f[i]]){
			b[f[i]]= ++top;
			d[i]= top;
		}else d[i]= b[f[i]];
	}
	printf("%d\n",top);
	for (i= 1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
