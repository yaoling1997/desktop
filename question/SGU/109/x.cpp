#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 200;
int n,m,i,j;
int h(int x,int y){
	return (x-1)*n+y;
}
void go(int x,int y){
	while (x<=n&&y>0){
		printf(" %d",h(x,y));
		x++,y--;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	if (n==2){
		printf("3 4\n5 2 3");
	}else {
		printf("%d",n);
		for (i= 3;i<=n;i++)
			go(i,n);
		printf("\n");
		m= n+1;
		if ((m&1)==0) m++;
		printf("%d",m);
		go(2,n);
		printf("\n");
		for (i= n;i>1;i--){
			m+= 2;
			printf("%d",m);
			go(1,i);
			printf("\n");
		}
	}return 0;
}
