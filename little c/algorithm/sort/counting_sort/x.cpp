#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=3001,maxm= 100000;
int a[maxn],b[maxn],c[maxm];
int i,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	for (i= 1;i<maxm;i++)
		c[i]+= c[i-1];
	for (i= n;i>0;i--){
		b[c[a[i]]]= a[i];
		c[a[i]]--;
	}
	for (i= 1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}
