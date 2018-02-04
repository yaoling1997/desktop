#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e4,oo= 1e8;
int b[maxn],X[maxn],Y[maxn],f[maxn],p[maxn],ans[maxn];
int i,n,la,cnt;
int dfs(int o){
	int &F= f[o],i;
	if (F!=-1) return F;
	F= oo;
	for (i= 1;i<=la;i++){
		if (b[i]) continue;
		if (X[i]>o) break;
		int x= dfs(o-X[i])+1;
		if (x<F){
			F= x;
			p[o]= X[i];
		}
	}return F;
}
void get(int o){
	if (!o) return;
	cnt++;
	ans[cnt]= p[o];
	get(o-p[o]);
}
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 2;i<=n;i++){
		if (b[i]) continue;
		la++;
		X[la]= i;
		Y[i]= la;
		int p= i*i;
		while (p<=n){
			b[p]= 1;
			p+= i;
		}
	}
	b[1]= 1;
	memset(f,-1,sizeof(f));
	f[0]= 0;
	dfs(n);
	if (f[n]==oo) printf("0");
	else {
		get(n);
		sort(ans+1,ans+cnt+1,cmp);
		printf("%d\n",cnt);
		for (i= 1;i<=cnt;i++)
			printf("%d%c",ans[i],i<cnt?' ':'\n');
	}return 0;
}
