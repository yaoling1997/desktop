#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
double pi= acos(-1);
double d,h,v,e,r,s,t;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%lf%lf%lf%lf",&d, &h, &v, &e);
	r= d/2;
	s= r*r*pi;
	v/= s;
	if (v<=e) printf("NO");
	else {
		v-= e;
		t= h/v;
		if (t>1e4) printf("NO");
		else printf("YES\n%.12lf",t);
	}return 0;
}