#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<sys/timeb.h>
using namespace std;
int n,m,T,i,x,y;
int random(int o){return rand()%o;}
int main()
{
	freopen("1.in","w",stdout);
	struct timeb t;ftime(&t);
	srand(t.time*1000+t.millitm);
	T= random(3)+1;
	printf("%d\n",T);
	for (int a1= 1;a1<=T;a1++){
		n= random(50)+3;m= random(5)+100;		
		printf("%d %d\n",n, m);
		for (i= 1;i<=m;i++){
			x= random(n)+1;y= random(n)+1;
			printf("%d %d\n",x,y);
		}
	}
	cout<<t.time<<" "<<t.millitm;
	return 0;
}
