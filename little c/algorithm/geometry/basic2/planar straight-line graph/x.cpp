#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
const double eps= 1e-8;
struct point{
	double x,y;
};
typedef point vec;
typedef vector<point> polygon;
struct edge{
	int from,to;
	double ang;
};
vector<edge> edges;
vector<polygon> faces;
vector<int> g[maxn];
double X[maxn],Y[maxn],area[maxn];
int prev[maxn],vis[maxn],left[maxn];
int n,m,i,j,cnt;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0 || (!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
bool cmp(int a,int b){return edges[a].ang<edges[b].ang;}
double getAngle(int from,int to){
	return atan2(Y[to]-Y[from],X[to]-X[from]);
}
double arean(polygon poly){
	int n= poly.size(),i;
	double area= 0;
	for (i= 1;i<n-1;i++)
		area+= cj(poly[i]-poly[0],poly[i+1]-poly[0]);
	return area/2;
}
void addedge(int from,int to){
	edges.push_back((edge){from,to,getAngle(from,to)});
	edges.push_back((edge){to,from,getAngle(to,from)});
	int m= edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}
void build(int n){
	int len,i,j;
	for (i= 1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),cmp);
		len= g[i].size();
		for (j= 0;j<len;j++)
			prev[g[i][(j+1)%len]]= g[i][j];
	}
	memset(vis,0,sizeof(vis));
	cnt= 0;
	for (i= 1;i<=n;i++){
		len= g[i].size();
		for (j= 0;j<len;j++){
			int e= g[i][j];
			if (!vis[e]){
				cnt++;				
				polygon poly;
				for (;;){
					vis[e]= 1;left[e]= cnt;
					int from= edges[e].from;
					poly.push_back((point){X[from],Y[from]});
					e= prev[e^1];
					if (e==g[i][j]) break;
				}
				area[cnt]= arean(poly);
				if (area[cnt]>0)
					faces.push_back(poly);
				else cnt--;
			}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%lf %lf",&X[i], &Y[i]);
	for (i= 1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x, &y);
		addedge(x,y);
	}
	build(n);
	for (i= 0;i<cnt;i++){
		int len= faces[i].size();
		for (j= 0;j<len;j++)
			printf("%.3lf %.3lf\n",faces[i][j].x, faces[i][j].y);
		printf("\n");
	}
	return 0;
}
