#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxm= 10000;
int c[maxm+10];
int T,a1,n,m,i,j,x,ans,sum;
void init(){
	int i,j,x,cnt;
	for (i= 1;i<=maxm;i++){
		x= i;cnt= 0;
		for (j= 2;j<=sqrt(x+0.5);j++)
			if (x%j==0){
				while (x%j==0)
					x/= j,cnt++;
				if (x==1) break;
			}
		if (x!=1) cnt++;
		c[i]= cnt;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	init();
	for (a1= 1;a1<=T;a1++){
		ans= 0;
		scanf("%d %d",&n, &m);
		for (i= 1;i<=n;i++){
			sum= 0;
			for (j= 1;j<=m;j++){
				scanf("%d",&x);
				sum+= c[x];
			}
			ans^= sum;
		}
		if (ans) printf("Case #%d: YES\n",a1);
		else printf("Case #%d: NO\n",a1);
	}
	return 0;
}
