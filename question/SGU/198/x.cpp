#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-12;
const int maxn= 500;
struct point{
	double x,y;
};
typedef point vec;
struct circle{
	point c;
	double r;
}C[maxn];
struct edge{
	int v;
	double w;
};
vector<edge> g[maxn];
queue<int> Q;
double d[maxn];
int vis[maxn],t[maxn];
point O;
double x,y,z;
int n,i,j,cnt;
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
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double length(vec a){return sqrt(dj(a,a));}
double angle(vec a,vec b){
	return asin(cj(a,b)/length(a)/length(b));
}
int spfa(){
	while (!Q.empty()) Q.pop();
	int i;
	for (i= 1;i<=n;i++){
		vis[i]= 1;
		Q.push(i);
		t[i]= 1;
	}
	while (!Q.empty()){
		int u= Q.front(),len= g[u].size();
		Q.pop();
		vis[u]= 0;
		for (i= 0;i<len;i++){
			int v= g[u][i].v;
			double w= g[u][i].w;
			if (dcmp(d[v]-d[u]-w)>0){
				d[v]= d[u]+w;
				if (!vis[v]){
					vis[v]= 1;
					Q.push(v);
					t[v]++;
					if (t[v]>n) return 0;
				}
			}
		}
	}return 1;
}
double rad(circle a,circle b){
	return atan2(cj(a.c-O,b.c-O),dj(a.c-O,b.c-O));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);	
	while (scanf("%d",&n)>0){
		cnt++;
		if (cnt==2){
			for(;;);
		}
		for (i= 1;i<=n;i++){
			scanf("%lf%lf%lf",&x, &y, &z);
			C[i]= (circle){x,y,z};
		}
		scanf("%lf%lf%lf",&x, &y, &z);
		O= (point){x,y};
		for (i= 1;i<=n;i++)
			C[i].r+= z;
		for (i= 1;i<=n;i++)
			for (j= i+1;j<=n;j++){
				double d= length(C[j].c-C[i].c);
				//if (d>=C[i].r+C[j].r-eps) continue;
				if (dcmp(d-C[i].r-C[j].r)>=0) continue;
				double da= angle(C[i].c-O,C[j].c-O);
				//da= rad(C[i],C[j]);
				g[i].push_back((edge){j,da});
				g[j].push_back((edge){i,-da});
			}
		if (spfa()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
