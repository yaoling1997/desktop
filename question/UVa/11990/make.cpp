#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;
const int maxn= 300001;
int a[maxn],b[maxn];
int x,y,i,n,m;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	for (int t= 1;t<=3;t++){
		n= 200000;m= 70000;
		printf("%d %d\n",n,m);
		for (i= 1;i<=n;i++){
			a[i]= i;
			b[i]= i;
		}
		for (i= 1;i<=random(n)+1;i++){
			x= random(n)+1;y= random(n)+1;
			swap(a[x],a[y]);
			x= random(n)+1;y= random(n)+1;
			swap(b[x],b[y]);
		}
		for (i= 1;i<=n;i++)
			printf("%d\n",a[i]);
		for (i= 1;i<=m;i++)
			printf("%d\n",b[i]);
	}
	return 0;
}
