#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
ll ans;
ll a,b,c,x1,x2,yy1,y2,X,Y,x,y,r,A,B,P,Q;
ll gcd(ll a,ll b,ll &x,ll &y){
	if (!b){
		x= 1;
		y= 0;
		return a;
	}
	ll re= gcd(b,a%b,x,y);
	ll t= x;
	x= y;
	y= t-a/b*y;
	return re;
}
ll get(ll a,ll b,ll p,ll q){
	if (a>p) swap(a,p),swap(b,q);
	if (b<p) return 0;
	return min(b,q)-p+1;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld%lld",&a, &b, &c);
	scanf("%lld%lld%lld%lld",&x1, &x2, &yy1, &y2);
	X= x2-x1+1;Y= y2-yy1+1;
	c= -c;
	if (c<0){
		a= -a;
		b= -b;
		c= -c;
	}
	if (a==0&&b==0){
		if (c==0)
			ans= X*Y;
		else ans= 0;
	}else if (a==0){
		if (c%b) ans= 0;
		else if (yy1<=c/b&&c/b<=y2) ans= X;
		else ans= 0;
	}else if (b==0){
		if (c%a) ans= 0;
		else if (x1<=c/a&&c/a<=x2) ans= Y;
		else ans= 0;		
	}else {
		if (a<0){
			a*= -1;
			x1*= -1;
			x2*= -1;
			swap(x1,x2);
		}
		if (b<0){
			b*= -1;
			yy1*= -1;
			y2*= -1;
			swap(yy1,y2);
		}			
		r= gcd(a,b,x,y);
		if (c%r) ans= 0;
		else {
			a/= r;b/= r;c/= r;
			x*= c;y*= c;
			A= ceil(1.0*(x1-x)/b);
			B= floor(1.0*(x2-x)/b);
			P= ceil(1.0*(y-y2)/a);
			Q= floor(1.0*(y-yy1)/a);
			ans= get(A,B,P,Q);
		}
	}
	printf("%lld",ans);
	return 0;
}
