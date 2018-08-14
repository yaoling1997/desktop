#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<sys/timeb.h>
#define ll long long
using namespace std;
const int maxn= 50;
struct node{
	int x,y;
}P[maxn];
int a[maxn][maxn];
int per[maxn];
int n,m,q,i,o,x,y,z,la,now,cnt;
int random(int o){
	return rand()%o;
}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	n= 1;m= random(5)+3;q= 3;
	printf("%d %d %d\n",n, m, q);
	now= 2;
	for (i= 1;i<=q;i++){
		o= random(3)+1;
		if (o==3&&!la) o= 2;
		if (o==1){
			do x= random(n)+1,y= random(m)+1;
			while (a[x][y]);			
		}else if (o==2){
			do x= random(n)+1,y= random(m)+1;
			while (a[x][y]);			
			a[x][y]= 1;
			P[++cnt]= (node){x,y};
			per[++la]= cnt;
		}else {
			random_shuffle(per+1,per+la+1);
			x= P[per[la]].x;
			y= P[per[la]].y;
			a[x][y]= 0;
			la--;
		}
		z= now+random(2)+1;
		printf("%d %d %d %d\n",o, x, y, z);
		now= z;
	}return 0;
}
