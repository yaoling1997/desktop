#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int i,n,len,s;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	s= n;
	for (i= 2;i<=sqrt(n+0.5);i++)
		if (n%i==0){
			while (n%i==0)
				n/= i;
			s= s/i*(i-1);
		}
	if (n!=1)
		s= s/n*(n-1);
	printf("%d",s);
	return 0;
}
