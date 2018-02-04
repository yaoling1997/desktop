#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int i;
void putint(int a){
	if (a<0){
		putchar('-');
		a= -a;
	}
	while (a>=10){
		putint(a/10);
	}putchar(a%10+'0');
}
int main()
{
	freopen("1.out","w",stdout);
	for (i= 1;i<=1e7;i++)
		putint(-10000);
	return 0;
}
