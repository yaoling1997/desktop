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
struct point{
	double x,y;
}P[maxn];
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double x,y;
int ans,n,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n+1;i++){
		scanf("%lf%lf",&x, &y);
		P[i]= (point){x,y};
	}
	P[n+2]= P[2];
	for (i= 1;i<=n;i++)
		if (cj(P[i+1]-P[i],P[i+2]-P[i])>0) ans++;
	printf("%d\n",ans);
	return 0;
}