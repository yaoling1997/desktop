#include<cstdio>
#define ll long long
using namespace std;
int i,n;
ll F[2];
ll sum;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	if (n==1){
		printf("1");
		return 0;
	}
	F[1]= F[0]= 1;
	sum= 2;
	for (i= 3;i<=n;i++){
		F[i%2]= F[0]+F[1];
		sum+= F[i%2];
	}
	printf("%lld",sum);
	return 0;
}
