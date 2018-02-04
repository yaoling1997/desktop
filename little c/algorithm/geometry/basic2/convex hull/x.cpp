#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 3001;
struct point{
	double x,y;
};
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(double t,vec a){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return (a.x<b.x) || (a.x==b.x && a.y<b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
bool cmp(point a,point b){return a<b;}
point p[maxn],ch[maxn];
int n,m,i;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++)	scanf("%lf %lf\n",&p[i].x, &p[i].y);
	sort(p+1,p+n+1,cmp);
	for (i= 1;i<=n;i++){
		while (m>1 && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	int k= m;
	for (i= n-1;i>=1;i--){
		while (m>k && cj(ch[m]-ch[m-1],p[i]-ch[m-1])<=0) m--;
		ch[++m]= p[i];
	}
	if (m>1) m--;
	for (i= 1;i<=m;i++) printf("%.2lf %.2lf\n",ch[i].x, ch[i].y);
	return 0;
}
