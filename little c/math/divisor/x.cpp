#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,i;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	int ss= (int)(sqrt(n)+0.000001);
	for (i= 2;i<=ss;i++)
		if (n%i==0){
			printf("%d ",i);
			while (n%i==0)
				n/= i;
		}
	if (n!=1) printf("%d",n);
	return 0;
}
