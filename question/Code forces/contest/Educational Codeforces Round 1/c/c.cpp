#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ld long double
#define ll long long
using namespace std;
const int maxn= 3e5,oo= 1e9;
struct point{
	ld x,y;
	int h;
};
typedef point vec;
vec a[maxn];
int ans[2];
ld now,x,y;
double xx,yy;
int i,n;
ld polarAngle(vec a){
	return atan2(a.y,a.x);
}
ld dj(vec a,vec b){
	return a.x*b.x+a.y*b.y;
}
ld length(vec a){
	return sqrt(dj(a,a));
}
ld angle(vec a,vec b){
	return acos(dj(a,b)/length(a)/length(b));
}
bool cmp(vec a,vec b){
	return polarAngle(a)<polarAngle(b);
}
int main()
{
	now= oo;
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&xx, &yy);
		x= xx;
		y= yy;
		a[i]= (vec){x,y,i};
	}
	sort(a+1,a+n+1,cmp);
	for (i= 1;i<n;i++){
		vec p= a[i],q= a[i+1];
		x= polarAngle(q)-polarAngle(p);
		if (now>x){
			now= x;
			ans[0]= a[i].h;
			ans[1]= a[i+1].h;
		}
	}
	x= angle(a[1],a[n]);
	if (now>x){
		now= x;
		ans[0]= a[1].h;
		ans[1]= a[n].h;		
	}
	printf("%d %d\n",ans[0], ans[1]);
	return 0;
}
