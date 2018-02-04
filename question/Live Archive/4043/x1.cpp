#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 300;
struct point{
	int h,x,y;
}P[maxn],p;
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
int d[maxn];
int n,i,x,y;
void init(){
	
}
double polarAngle(point a){
	vec v= a-p;
	if (!v.x&&!v.y) return -1;
	return atan2(v.y,v.x);
}
bool cmp(point a,point b){
	return polarAngle(a)<polarAngle(b);
}
bool cmp2(point a,point b){
	return a.h<b.h;
}
int num(int x){
	return x>n?-1:1;
}
void go(int l,int r){
	if (l>r) return;
	int i,bl= 0;
	for (i= l;i<=r;i++)
		if (!bl||(P[i].y<p.y||(P[i].y==p.y&&P[i].x<p.x)))
			p= P[i],bl= 1;
	sort(P+l,P+r+1,cmp);
	int x= num(p.h);
	for (i= l+1;i<=r;i++){
		x+= num(P[i].h);
		if (x==0) break;
	}
	d[p.h]= P[i].h;
	d[P[i].h]= p.h;
	go(l+1,i-1);
	go(i+1,r);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		for (i= 1;i<=n;i++){
			scanf("%d%d",&x, &y);
			P[i]= (point){i,x,y};
		}
		for (i= 1;i<=n;i++){
			scanf("%d%d",&x, &y);
			P[n+i]= (point){n+i,x,y};
		}
		go(1,2*n);
		for (i= 1;i<=n;i++)
			printf("%d\n",d[i]-n);
	}return 0;
}
