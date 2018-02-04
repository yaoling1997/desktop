#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
using namespace std;
char c;
int n,m,q,i,j,x,y,z;
int random(int o){
	return rand()%o;
}
void get(){
	x= random(3);
	if (x==0){
		c= '<';
	}else if (x==1){
		c= '^';
	}else c= '>';

}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(0));
	n= random(500)+4;m= random(5)+4;q= random(5)+20;
	printf("%d %d %d\n",n, m, q);
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++){
			get();
			printf("%c",c);
		}
		printf("\n");
	}
	for (i= 1;i<=q;i++){
		x= random(2);
		if (x==0){
			printf("A %d %d\n",random(n)+1, random(m)+1);
		}else {
			get();
			printf("C %d %d %c\n",random(n)+1, random(m)+1, c);
		}
	}return 0;
}
