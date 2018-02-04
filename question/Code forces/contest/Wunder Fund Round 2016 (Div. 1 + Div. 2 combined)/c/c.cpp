#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 2e5;
struct point{
	ll x,y,h;
};
bool operator <(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
point p[maxn],a,b,c;
ll x,y,z,n,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld%lld",&x, &y);
		p[i]= (point){x,y,i};
	}
	sort(p+1,p+n+1);
	x= 1;y= 2;
	a= p[x];
	b= p[y];	
	for (z= 3;z<=n;z++){
		c= p[z];
		if ((b.y-a.y)*(c.x-b.x)==(b.x-a.x)*(c.y-b.y))
			continue;
		printf("%lld %lld %lld\n",p[x].h, p[y].h, p[z].h);
		return 0;
	}
}
