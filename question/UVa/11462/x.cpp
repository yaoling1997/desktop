#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int c[200];
int i,j,n,x,first;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF&&n){
		for (i= 1;i<=n;i++){
			scanf("%d",&x);
			c[x]++;
		}first= 1;
		for (i= 0;i<=100;i++){
			for (j= 1;j<=c[i];j++){
				if (!first) printf(" ");
				else first= 0;
				printf("%d",i);
			}
			c[i]= 0;
		}printf("\n");
	}return 0;
}
