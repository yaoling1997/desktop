#include<cstdio>
using namespace std;
int n,ans,i;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		if (gcd(i,n)==1) ans++;
	printf("%d\n",ans);
	return 0;
}
