#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int maxn= 2000;
char s[maxn][maxn];
int n,m,i,j,x,y,T,M;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	printf("%d\n",T);
	while (T--){
		n= random(5)+2;m= random(5)+2;
		printf("%d %d\n",n, m);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				s[i][j]= '.';
		x= random(n)+1;y= random(m)+1;
		s[x][y]= 'J';
		M= random(2);
		for (i= 1;i<=M;i++){
			do x= random(n)+1,y= random(m)+1;
			while (s[x][y]!='.');
			s[x][y]= 'F';
		}
		M= random(2);
		for (i= 1;i<=M;i++){
			do x= random(n)+1,y= random(m)+1;
			while (s[x][y]!='.');
			s[x][y]= '#';
		}
		for (i= 1;i<=n;i++)
			printf("%s\n",s[i]+1);
	}return 0;
}
