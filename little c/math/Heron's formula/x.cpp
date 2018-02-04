#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
double a,b,c,p;
int main()
{
	scanf("%lf %lf %lf",&a, &b, &c);
	p= (a+b+c)/2;
	printf("%lf",sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
