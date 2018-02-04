#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 100001;
int a[maxn],b[maxn];
int n,i,j,l1,l2,r1,r2,ans,bns;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)	scanf("%d",&a[i]);
	for (i= 1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (i= 1;i<=2;i++){
		l1= l2= 1;r1= r2= n;ans= bns= 0;
		while (l1<=r1){
			while (l1<=r1&&a[l1]>b[l2])
				ans+= 2,l1++,l2++;
			while (l1<=r1&&a[r1]>b[r2])
				ans+= 2,r1--,r2--;
			if (l1<=r1){
				if (a[l1]==b[r2]) ans++;else bns++;bns++;
				l1++;r2--;
			}
		}
		if (i==1){
			printf("%d ",ans);
			for (j= 1;j<=n;j++)
				swap(a[j],b[j]);
		}else printf("%d",bns);
	}return 0;	
}
