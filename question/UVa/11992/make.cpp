#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<sys/timeb.h>
using namespace std;
const int M= 20000;
int n,T,i,j,x,y,r,c,v,opt,x1,x2,y1,y2,m;
int R(int o){
	return rand()%o;
}
int main()	
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= 1;
	while (T--){
		r= R(20)+1,c= R(5e4)+1;m= R(M)+2;
		printf("%d %d %d\n",r, c, m);
		for (i= 1;i<=m;i++){
			opt= R(3)+1;
			printf("%d ",opt);
			if (opt==1){
				x2= R(r)+1;x1= R(x2)+1;
				y2= R(c)+1;y1= R(y2)+1;
				printf("%d %d %d %d %d\n",x1, y1, x2, y2, R(1e4));
			}else if (opt==2){
				x2= R(r)+1;x1= R(x2)+1;
				y2= R(c)+1;y1= R(y2)+1;
				printf("%d %d %d %d %d\n",x1, y1, x2, y2, R(1e4));				
			}else {
				x2= R(r)+1;x1= R(x2)+1;
				y2= R(c)+1;y1= R(y2)+1;
				printf("%d %d %d %d\n",x1, y1, x2, y2);				
			}
		}
	}return 0;
}
