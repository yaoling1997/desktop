#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2e5;
int a[maxn];
int n,m,i,j,x,y,z,T;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(1)+50;
	printf("%d\n",T);
	while (T--){
		n= random(10)+2;
		for (i= 1;i<=n;i++)
			a[i]= i;
		int bl= 1;
		for (;bl;){
			bl= 0;
			random_shuffle(a+1,a+n+1);
			for (i= 1;i<=n;i++)
				if (a[i]==i){
					bl= 1;
					break;
				}
		}
		printf("%d\n",n);
		for (i= 1;i<=n;i++)
			printf("%d%c",a[i],i<n?' ':'\n');
	}return 0;
}
