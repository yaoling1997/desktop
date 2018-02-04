#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
int a,mo,x;
int Fermat(ll a,int b){
	b-= 2;ll t= 1;
	while (b){
		if (b & 1) t= t*a%mo;
		b>>= 1;a= a*a%mo;
	}
	return t;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&a, &mo);
	x= Fermat(a,mo);
	printf("%d",x);
	return 0;
}
