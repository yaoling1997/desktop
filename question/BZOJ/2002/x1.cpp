#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 300001;
int a[maxn];
int i,m,n,x,y,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);ans= 0;
			while (x<n){
				ans++;
				x+= a[x];
			}
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&x, &y);
			a[x]= y;
		}
	}
	return 0;
}
