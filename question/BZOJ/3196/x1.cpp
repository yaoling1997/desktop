#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3001,oo= 1e9;
int a[maxn],c[maxn];
int x,y,z,n,m,i,j,t,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &m);
	c[0]= oo;
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (t= 1;t<=m;t++){
		scanf("%d",&x);ans= 0;
		if (x==1){
			scanf("%d %d %d",&x, &y, &z);
			for (j= x;j<=y;j++)
				if (a[j]<z) ans++;
			printf("%d\n",ans+1);
		}else if (x==2){
			scanf("%d %d %d",&x, &y, &z);
			int g= y-x+1;
			for (i= x;i<=y;i++)
				c[i-x+1]= a[i];
			sort(c+1,c+g+1);
			printf("%d\n",c[z]);
		}else if (x==3){
			scanf("%d %d",&x, &y);
			a[x]= y;
		}else if (x==4){
			scanf("%d %d %d",&x, &y, &z);
			int g= y-x+1;
			for (i= x;i<=y;i++)
				c[i-x+1]= a[i];
			sort(c+1,c+g+1);
			for (i= 1;i<=g;i++)
				if (c[i]>=z) break;
			printf("%d\n",c[i-1]);
		}else {
			scanf("%d %d %d",&x, &y, &z);
			int g= y-x+1;
			for (i= x;i<=y;i++)
				c[i-x+1]= a[i];
			sort(c+1,c+g+1);
			for (i= 1;i<=g;i++)
				if (c[i]>z) break;
			if (i>g) {printf("%d\n",oo);continue;}
			printf("%d\n",c[i]);
		}
	}
	return 0;
}
