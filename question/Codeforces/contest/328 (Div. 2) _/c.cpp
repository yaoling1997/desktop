#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
ll t,w,b,G,L,p,q,y,D;
double x;
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld%lld%lld",&t, &w, &b);
	if (w<b) swap(w,b);
	if (b>t){
		printf("1/1");
		return 0;
	}
	G= gcd(w,b);
	x= 1.0*w/G*b;
	q= t;
	if (x>t){
		p= b-1;
		y= gcd(p,q);
		p/= y;
		q/= y;
		printf("%lld/%lld",p,q);
	}else {
		L= w/G*b;
		if (L<=b){
			printf("1/1");
			return 0;
		}
		D= t/L;
		p= D*b+min(b,t-D*L+1)-1;
		y= gcd(p,q);
		p/= y;
		q/= y;
		printf("%lld/%lld",p, q);
	}return 0;
}
