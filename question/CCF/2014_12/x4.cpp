#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 2e5;
struct edge{
	int x,y,z;
};
edge a[maxn];
int f[maxn];
int n,m,x,y,z,i,ans;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
bool cmp(edge x,edge y){
	return x.z<y.z;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		a[i]= (edge){x,y,z};
	}
	sort(a+1,a+m+1,cmp);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=m;i++){
		x= a[i].x;
		y= a[i].y;
		z= a[i].z;
		if (find(x)!=find(y)){
			ans+= z;
			f[f[x]]= f[y];
		}
	}
	printf("%d",ans);
	return 0;
}

