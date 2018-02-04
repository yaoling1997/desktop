#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 3001,oo= 1e8;
const double eps= 1e-8;
struct edge{
	int v;
	double w;
};
struct point{
	int x,y;
};
vector<edge> g[maxn];
point a[maxn];
int d[maxn],s[maxn],t[maxn];
double lx[maxn],ly[maxn];
int n,i,j,x,y,cnt;
bool dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
double length(double x,double y,double x1,double y1){
	return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
void addedge(int x,int y,double z){
	g[x].push_back((edge){y,-z});cnt++;
}
bool match(int o){
	s[o]= 1;int i,len= g[o].size();
	for (i= 0;i<len;i++){
		int v= g[o][i].v;
		if (!t[v] && !dcmp(lx[o]+ly[v]-g[o][i].w)){
			t[v]= 1;
			if (!d[v] || match(d[v])){
				d[v]= o;
				return 1;
			}
		}			
	}return 0;
}
void update(){
	double a= oo;int i,j;
	for (i= 1;i<=n;i++)
		if (s[i]){
			int len= g[i].size();
			for (j= 0;j<len;j++){
				int v= g[i][j].v;
				if (!t[v])
					a= min(a,lx[i]+ly[v]-g[i][j].w);
			}
		}
	for (i= 1;i<=n;i++){
		if (s[i]) lx[i]-= a;
		if (t[i]) ly[i]+= a;
	}
}
void init(int n){
	int i;
	for (i= 1;i<=n;i++)
		g[i].clear();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		init(n);
		for (i= 1;i<=n;i++)
			scanf("%d %d",&a[i].x, &a[i].y);
		for (i= 1;i<=n;i++){
			scanf("%d %d",&x, &y);
			for (j= 1;j<=n;j++)
				addedge(i,j,length(x,y,a[j].x,a[j].y));
		}
		for (i= 1;i<=n;i++){
			ly[i]= d[i]= 0;
			lx[i]= 0;
			int len= g[i].size();
			for (j= 0;j<len;j++)
				lx[i]= max(lx[i],g[i][j].w);
		}
		for (i= 1;i<=n;i++)
			for(;;){
				for (j= 1;j<=n;j++) s[j]= t[j]= 0;
				if (match(i)) break;
				else update();
			}
		for (i= 1;i<=n;i++)
			printf("%d\n",d[i]);
	}
	return 0;
}
