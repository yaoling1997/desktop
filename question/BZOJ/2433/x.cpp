#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const double eps= 1e-8,oo= 1e8;
const int maxn= 30001;
struct point{
	double x,y;
	void init(){x= y= oo;}
};
struct edge{
	int v;
	double w;
};
struct node{
	int v;
	double d;
	bool operator <(const node &a)const{
		return a.d<d;
	}
};
typedef point vec;
vector<edge> g[maxn];
point a[maxn],b[maxn];
point ps,pt,v1,v2;
double d[maxn];
double x,xx,y,yy,V,ans;
int n,i,tt,s,t;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double length(vec a){return sqrt(dj(a,a));}
bool cmp(point a,point b){return a<b;}
void addedge(int from,int to,double cost){
	g[from].push_back((edge){to,cost});
}
void dijsktra(){
	priority_queue<node> Q;
	int i,vis[maxn]= {0};
	for (i= 1;i<=t;i++) d[i]= oo;
	d[s]= 0;vis[s]= 0;
	Q.push((node){s,0});
	while (!Q.empty()){
		int u= Q.top().v,len= g[u].size();
		Q.pop();
		if (vis[u]) continue;
		vis[u]= 1;
		for (i= 0;i<len;i++){
			double w= g[u][i].w;
			int v= g[u][i].v;
			if (d[v]>d[u]+w){
				d[v]= d[u]+w;
				Q.push((node){v,d[v]});
			}
		}
	}
}
double solve(){
	int i,j,bl;
	v1.init();v2.init();
	bl= 1;
	for (i= 1;i<=tt;i++){
		if (dcmp(a[i].x-ps.x)>=0){
			if (v1.x==oo||(dcmp(cj(v1-ps,a[i]-ps))>=0)){
				if (v2.x!=oo&&dcmp(cj(v2-ps,a[i]-ps))>0){
					bl= 0;
					break;
				}
				addedge(s,i,length(a[i]-ps));
				v1= a[i];
			}
		}
		if (dcmp(b[i].x-ps.x)>=0){
			if (v2.x==oo||(dcmp(cj(v2-ps,b[i]-ps))<=0)){
				if (v1.x!=oo&&dcmp(cj(v1-ps,b[i]-ps))<0){
					bl= 0;					
					break;
				}
				addedge(s,i+tt,length(b[i]-ps));
				v2= b[i];
			}
		}
	}
	if (bl&&dcmp(cj(v1-ps,pt-ps))>=0&&dcmp(cj(v2-ps,pt-ps))<=0)
		return length(pt-ps);
	for (i= 1;i<=tt;i++){
		bl= 1;
		v1.init();v2.init();
		for (j= i+1;j<=tt;j++){
			if (dcmp(a[j].x-a[i].x)>=0){
				if (v1.x==oo||(dcmp(cj(v1-a[i],a[j]-a[i]))>=0)){
					if (v2.x!=oo&&dcmp(cj(v2-a[i],a[j]-a[i]))>0){
						bl= 0;
						break;
					}
					addedge(i,j,length(a[j]-a[i]));
					v1= a[j];
				}
			}
			if (dcmp(b[j].x-a[i].x)>=0){
				if (v2.x==oo||(dcmp(cj(v2-a[i],b[j]-a[i]))<=0)){
					if (dcmp(cj(v1-a[i],b[j]-a[i]))<0){
						bl= 0;
						break;
					}
					addedge(i,j+tt,length(b[j]-a[i]));
					v2= b[j];
				}
			}			
		}
		if (bl&&dcmp(cj(v1-a[i],pt-a[i]))>=0&&dcmp(cj(v2-a[i],pt-a[i]))<=0)
			addedge(i,t,length(pt-a[i]));
		addedge(i,i+tt,length(b[i]-a[i]));
		addedge(i+tt,i,length(b[i]-a[i]));		
	}
	for (i= 1;i<=tt;i++){
		bl= 1;		
		v1.init();v2.init();
		for (j= i+1;j<=tt;j++){
			if (dcmp(a[j].x-b[i].x)>=0){
				if (v1.x==oo||(dcmp(cj(v1-b[i],a[j]-b[i]))>=0)){
					if (v2.x!=oo&&dcmp(cj(v2-b[i],a[j]-b[i]))>0){
						bl= 0;
						break;
					}					
					addedge(i+tt,j,length(a[j]-b[i]));
					v1= a[j];
				}
			}
			if (dcmp(b[j].x-b[i].x)>=0){
				if (v2.x==oo||(dcmp(cj(v2-b[i],b[j]-b[i]))<=0)){
					if (dcmp(cj(v1-b[i],b[j]-b[i]))<0){
						bl= 0;
						break;
					}
					addedge(i+tt,j+tt,length(b[j]-b[i]));
					v2= b[j];
				}
			}			
		}
		if (bl&&dcmp(cj(v1-b[i],pt-b[i]))>=0&&dcmp(cj(v2-b[i],pt-b[i]))<=0)
			addedge(i+tt,t,length(pt-b[i]));		
	}
	dijsktra();
	return d[t];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf %lf %lf",&x, &y, &xx, &yy);
		a[++tt]= (point){x,y};
		b[tt]= (point){x,yy};
		a[++tt]= (point){xx,y};
		b[tt]= (point){xx,yy};
	}scanf("%lf %lf %lf %lf %lf",&x, &y, &xx, &yy, &V);
	ps= (point){x,y};
	pt= (point){xx,yy};
	s= 2*tt+1;t= s+1;
	ans= solve();
	printf("%.8lf",ans/V);
	return 0;
}

