#include<cstdio>
#include<cstdlib>
int main()
{
	freopen("1.out","w",stdout);
	int b=10;
	int &a=b;
	printf("%d\n",b);
	a=5;
	printf("%d",b);
	return 0;
}
