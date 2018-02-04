#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int n,t,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &t);
	if (t==10){
		if (n==1) printf("-1");
		else {
			printf("%d",t);
			n-= 2;
			for (i= 1;i<=n;i++)
				printf("0");
		}
	}else {
		printf("%d",t);
		n--;
		for (i= 1;i<=n;i++)
			printf("0");
	}return 0;
}
