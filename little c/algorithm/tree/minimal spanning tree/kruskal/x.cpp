#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001;
struct edge {
	int x,y,z;
};
int f[maxn];
edge a[maxn];
int i,n,m,ans,s;
int find(int o){
	if (f[o]==o) return f[o];
	f[o]= find(f[o]);
	return f[o];
}
bool cmp(edge a,edge b){return a.z<b.z;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++)
		scanf("%d %d %d",&a[i].x, &a[i].y, &a[i].z);
	for (i= 1;i<=n;i++) f[i]= i;
	sort(a+1,a+m+1,cmp);
	for (i= 1;i<=m;i++){
		find(a[i].x);
		find(a[i].y);
		if (f[a[i].x]!=f[a[i].y]){
			s++;ans+= a[i].z;
			f[f[a[i].x]]= f[a[i].y];
			if (s==n-1) break;
		}
	}
	printf("%d",ans);
	return 0;
}
