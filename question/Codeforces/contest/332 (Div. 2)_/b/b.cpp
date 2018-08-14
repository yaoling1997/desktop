#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
struct node{
	int x,h;
}f[maxn];
int vis[maxn],a[maxn],b[maxn],fuck[maxn];
int n,m,i,j,x,y,z;
bool cmp(node a,node b){
	return a.x<b.x;
}
int main()
{
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		vis[x]= 1;
		f[i]= (node){x,i};
	}
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		b[i]= x;
		if (!vis[x]){
			printf("Impossible");
			return 0;
		}vis[x]= 2;
	}
	for (i= 1;i<=n;i++){
		if (fuck[f[i].x]&&vis[f[i].x]==2){
			printf("Ambiguity");
			return 0;
		}
		fuck[f[i].x]= 1;
	}
	sort(f+1,f+n+1,cmp);
	for (i= 1;i<=m;i++){
		x= b[i];
		int l= 1,r= n+1;
		while (l+1<r){
			int mid= (l+r)>>1;
			if (f[mid].x>x) r= mid;
			else l= mid;
		}
		a[i]= f[l].h;
	}
	printf("Possible\n");
	for (i= 1;i<=m;i++)
		printf("%d%c",a[i],i<m?' ':'\n');
	return 0;
}
