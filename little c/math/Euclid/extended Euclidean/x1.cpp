#include<cstdio>
#include<cstdlib>
using namespace std;
int a,mo,x,y;
void gcd(int a,int b){
	if (!b){x= 1;y= 0;return;}
	gcd(b,a%b);
	int t= x;
	x= y;
	y= t-a/b*y;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&a, &mo);
	gcd(a,mo);
	x+= (x<0)*mo;
	printf("%d",x);
	return 0;
}
