#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 120,oo= 1e9;
int h[3000],ans[maxn];
int n,m,i,j,T,x,la;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d",&n);
		m= 2*n-1;
		memset(h,0,sizeof(h));
		for (i= 1;i<=m;i++)
			for (j= 1;j<=n;j++){
				scanf("%d",&x);
				h[x]++;
			}
		la= 0;
		for (i= 1;i<=2500;i++)
			if (h[i]&1)
				ans[++la]= i;
		for (i= 1;i<=la;i++)
			printf("%d%c",ans[i], i<la?' ':'\n');				
	}return 0;
}
