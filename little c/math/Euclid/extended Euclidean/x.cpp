#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int a,b,x,y;
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
	scanf("%d %d",&a, &b);
	gcd(a,b);
	printf("%d %d",x, y);
	return 0;
}
