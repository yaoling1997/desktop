#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 300001,oo= 1e8;
int c[maxn];
int n,m,i,j,k,x,y,z,p1,p2,ans,re;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int a1= 1;a1<=m;a1++){
		char ch;
		scanf("%c %c",&ch, &ch);
		if (ch=='I'){
			for (i= 1;i<=5;i++) scanf("%c",&ch);
			scanf("%d %d",&x, &y);
			for (i= n+y;i>=x+y+1;i--)
				c[i]= c[i-y];
			for (i= x+1;i<=x+y;i++)
				scanf("%d",&c[i]);
			n+= y;
		}else if (ch=='D'){
			for (i= 1;i<=5;i++) scanf("%c",&ch);
			scanf("%d %d",&x, &y);
			for (i= x+y;i<=n;i++)
				c[i-y]= c[i];
			for (i= n-y+1;i<=n;i++)
				c[i]= 0;
			n-= y;
		}else if (ch=='R'){
			for (i= 1;i<=6;i++) scanf("%c",&ch);
			scanf("%d %d",&x, &y);p1= x;p2= x+y-1;
			for (i= 1;i<=y/2;i++){
				swap(c[p1],c[p2]);
				p1++;p2--;
			}
		}else if (ch=='G'){
			for (i= 1;i<=6;i++) scanf("%c",&ch);
			scanf("%d %d",&x, &y);ans= 0;
			for (i= 1;i<=y;i++)
				ans+= c[x+i-1];
			printf("%d\n",ans);
		}else {
			scanf("%c %c",&ch, &ch);
			if (ch=='K'){
				for (i= 1;i<=6;i++) scanf("%c",&ch);
				scanf("%d %d %d",&x, &y, &z);y+= x-1;
				for (i= x;i<=y;i++)
					c[i]= z;
			}else {
				for (i= 1;i<=4;i++) scanf("%c",&ch);
				if (n==0) {printf("0\n");continue;}
				ans= -oo,re= -oo;
				for (i= 1;i<=n;i++){
					re= max(re+c[i],c[i]);
					ans= max(ans,re);
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
