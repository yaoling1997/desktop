#include<cstdio>
using namespace std;
int n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	printf("%d",(n/3)*2+(n%3==2));
	return 0;
}
