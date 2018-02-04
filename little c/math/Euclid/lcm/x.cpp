#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&a, &b);
	printf("%d",a/gcd(a,b)*b);
	return 0;
}
