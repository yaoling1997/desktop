#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 30001;
int a[maxn],c[maxn];
int n,m,i,j,bl,cost;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d %d",&n, &m)!=EOF){
		if (n==0 && m==0) break;
		for (i= 1;i<=n;i++)
			scanf("%d",&c[i]);
		for (i= 1;i<=m;i++)
			scanf("%d",&a[i]);
		sort(c+1,c+n+1);
		sort(a+1,a+m+1);
		j= 1;bl= 1;cost= 0;
		for (i= 1;i<=n;i++){
			while (a[j]<c[i] && j<=m)
				j++;
			if (j>m){
				bl= 0;
				break;
			}
			cost+= a[j++];
		}
		if (bl)	printf("%d\n",cost);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
