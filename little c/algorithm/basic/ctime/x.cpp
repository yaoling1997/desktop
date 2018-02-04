#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int beginTime= clock();
	for (int i= 0;i<=5e8;i++);
	int endTime= clock();
	printf("%.2lf",(endTime-beginTime)/1000.0);
	return 0;
}
