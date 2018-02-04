#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-6;
const int maxn= 3001;
struct point{
	int x,y;
};
vector<int> g[maxn];
point P[maxn][2];
int X[maxn],b[maxn],sta[maxn];
int x,y,xx,yy,i,n,tim,la;
double dist(point a,point b){
	double x= a.x-b.x,y= a.y-b.y;
	return sqrt(x*x+y*y);
}
int dcmp(double a){
	if (fabs(a)<eps) return 0;
	return a<0?-1:1;
}
bool dfs(int o){
	if (b[o]==tim) return 1;
	if (b[X[o]]==tim) return 0;
	sta[++la]= o;
	b[o]= tim;
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (!dfs(v)) return 0;
	}return 1;
}
bool solve(){
	tim++;
	for (int i= 1;i<=n;i++){
		if (b[i]==tim||b[X[i]]==tim) continue;
		if (!dfs(i)){
			while (la) b[sta[la--]]= 0;
			if (!dfs(X[i])) return 0;
		}
	}return 1;
}
bool judge(point a,point b,double r){
	return dcmp(dist(a,b)-2*r)>=0;
}
bool ok(double r){
	int i,j;
	for (i= 1;i<=n;i++) g[i].clear(),g[i+n].clear();
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++){
			if (!judge(P[i][0],P[j][0],r)){
				g[i].push_back(X[j]);
				g[j].push_back(X[i]);
			}
			if (!judge(P[i][0],P[j][1],r)){
				g[i].push_back(j);
				g[X[j]].push_back(X[i]);
			}
			if (!judge(P[i][1],P[j][0],r)){
				g[X[i]].push_back(X[j]);
				g[j].push_back(i);
			}
			if (!judge(P[i][1],P[j][1],r)){
				g[X[i]].push_back(j);
				g[X[j]].push_back(i);
			}
		}
	return solve();
}
void init(){
	int i;
	for (i= 1;i<=n;i++){
		g[i].clear();
		g[i+n].clear();
		X[i]= i+n;
		X[i+n]= i;
	}
}
int main()
{
	while (scanf("%d",&n)>0){
		init();
		for (i= 1;i<=n;i++){
			scanf("%d%d%d%d",&x, &y, &xx, &yy);
			P[i][0]= (point){x,y};
			P[i][1]= (point){xx,yy};
		}
		double l= 0,r= 20000;
		while (r-l>eps){
			double mid= (l+r)/2;
			if (ok(mid)) l= mid;
			else r= mid;
		}
		printf("%.2lf\n",l);
	}return 0;
}
