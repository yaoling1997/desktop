#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
char ch[2];
int T,i,j,C,R;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;ch[0]= '.';ch[1]= 'X';
	while (T--){
		R= random(4)+1;C= random(4)+1;
		printf("%d %d\n",R, C);
		for (i= 1;i<=R;i++){
			for (j= 1;j<=C;j++)
				printf("%c",ch[random(2)]);
			printf("\n");
		}
	}return 0;
}	
