#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-12,da= 1e-6;
const int maxn= 2e3;
struct point{
	double x,y;
};
typedef point vec;
struct seg{
	point a,b;
}S[maxn];
vector<int> g[maxn];
queue<int> Q;
point P[maxn];
int vis[maxn],b[maxn];
double x,y,xx,yy;
int i,j,n,m,s,t;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
bool onSeg(point a,point b,point p){
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<0;
}
bool xj(point a1,point a2,point b1,point b2){
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1)*dcmp(x2)<0&&dcmp(y1)*dcmp(y2)<0;
}
void init(){
	memset(vis,0,sizeof(vis));
	memset(b,0,sizeof(b));
	int i;
	for (i= 1;i<=m;i++)
		g[i].clear();
	m= 0;
}
bool ok(point p,point q){
	int i;
	for (i= 1;i<=n;i++)
		if (xj(p,q,S[i].a,S[i].b)) return 0;
	return 1;
}
bool nopath(int s){
	vis[s]= 1;
	Q.push(s);
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size(),i;
		Q.pop();
		for (i= 0;i<len;i++){
			int v= g[u][i];
			if (vis[v]) continue;
			vis[v]= 1;
			Q.push(v);
		}
	}
	return !vis[t];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&x, &y, &xx, &yy);
			S[i]= (seg){x,y,xx,yy};
			vec v= S[i].b-S[i].a;
			v= da*v/length(v);
			S[i].b= S[i].b+v;
			S[i].a= S[i].a-v;
			P[++m]= S[i].a;
			P[++m]= S[i].b;
		}
		for (i= 1;i<=m;i++)
			for (j= 1;j<=n;j++)
				if (onSeg(S[j].a,S[j].b,P[i])){
					b[i]= 1;
					break;
				}
		P[++m]= (point){0,0};
		P[++m]= (point){1000,1000};
		s= m-1;
		t= m;		
		for (i= 1;i<=m;i++){
			if (b[i]) continue;
			for (j= i+1;j<=m;j++){
				if (b[j]) continue;
				if (ok(P[i],P[j])){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		if (nopath(s)) printf("yes\n");
		else printf("no\n");
	}return 0;
}
