#include<cstdio>
#include<cstdlib>
using namespace std;
int x,y;
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&x, &y);
	printf("%d",gcd(x,y));
	return 0;
}
