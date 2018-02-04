#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,i,p,ans= 1;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	int ss= (int)(sqrt(n)+0.00000001);
	for (i= 2;i<=ss;i++)
		if (n%i==0){
			p= 1;
			while (n%i==0){
				p++;
				n/= i;
			}
			ans*= p;
		}
	if (n!=1) ans*= 2;
	printf("%d",ans);
}
