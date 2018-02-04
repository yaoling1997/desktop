#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<sys/timeb.h>
#include<vector>
using namespace std;
const int maxn= 3001,sig= 1e6;
vector<int> g;
int x,y,i,j,n,m,T;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	for (int b1= 1;b1<=10;b1++){
		g.clear();
		n= random(20000)+2;m= random(60000)+2;
		printf("%d %d\n",n, m);
		for (i= 1;i<=n;i++)
			printf("%d\n",random(sig));
		for (i= 1;i<=m;i++){
			do x= random(n)+1,y= random(n)+1;
			while (x==y);
			printf("%d %d\n",x, y);
			g.push_back(i);
		}
		random_shuffle(g.begin(),g.end());
		T= random(300000)+2;
		for (int a1= 1;a1<=T;a1++){
			x= random(3)+1;
			if (a1==T) x= 2;
			if (x==1&&g.size()==0) x= 2;
			if (x==1){
				//printf("D %d\n",g[g.size()-1]);g.pop_back();
				printf("D %d\n",random(m)+1);				
			}else if (x==2){
				x= random(n)+1;y= random(5)+1;
				printf("Q %d %d\n",x,y);
			}else {
				x= random(n)+1;
				printf("C %d %d\n",x, random(sig));
			}
		}
		printf("E\n");
	}
	printf("0 0");
	return 0;
}
