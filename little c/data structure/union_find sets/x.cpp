#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 1000;
int f[maxn];
int n,m,x,y,i;
bool b[maxn];
int find(int o){
	if (f[o]==o) return f[o];
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
		scanf("%d %d",&x,&y);
		find(x);
		find(y);
		f[f[x]]= f[y];
	}
	for (i= 1;i<=n;i++){
		find(i);
		b[f[i]]= true;
	}
	int ans= 0;
	for (i= 1;i<=n;i++)
		if (b[i]) ans++;
	printf("%d",ans);
	return 0;
}
	
