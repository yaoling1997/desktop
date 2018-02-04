#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<sys/timeb.h>
using namespace std;
const int sig= 3,maxn= 200;
int a[maxn],B[maxn][maxn];
int n,r,g,b,m,i,j,p;
int random(int o){return rand()%o;}
bool ok(int m,int *a){
	int i,j,bl;
	for (i= 1;i<=m;i++){
		bl= 0;
		for (j= 1;j<=n;j++)
			if (a[j]!=B[i][j]){
				bl= 1;
				break;
			}
		if (!bl) return 0;
	}return 1;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	//r= random(3);b= random(3);g= random(3);m= random(3);p= 7;
	r= random(3)+1;b= random(2);g= random(2);m= 1;p= 7;	
	n= r+b+g;
	printf("%d %d %d %d %d\n",r, g, b, m, p);
	for (i= 1;i<=n;i++)	a[i]= i;
	for (i= 1;i<=m;i++){
		for (;;){
			random_shuffle(a+1,a+n+1);
			if (ok(i,a)){
				for (j= 1;j<=n;j++)
					printf("%d%c",a[j],j<n?' ':'\n');
				memcpy(B[i],a,sizeof(a));
				break;
			}
		}
	}return 0;
}
