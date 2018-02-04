#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 3001,oo= 1e8;
struct point{
	double x,y;
};
struct node{
	double x,y;
	int split,l,r,left,right;
};
point P[maxn];
node a[maxn];
point ans;
double x,y,now;
int root,tot,n,m,i;
double Fx(int l,int r){
	double x= 0,re= 0;
	int i;
	for (i= l;i<=r;i++)
		x+= P[i].x;
	x/= r-l+1;
	for (i= l;i<=r;i++)
		re+= (P[i].x-x)*(P[i].x-x);
	return re/= r-l+1;
}
double Fy(int l,int r){
	double y= 0,re= 0;
	int i;
	for (i= l;i<=r;i++)
		y+= P[i].y;
	y/= r-l+1;
	for (i= l;i<=r;i++)
		re+= (P[i].y-y)*(P[i].y-y);
	return re/= r-l+1;
}
bool cmpx(point a,point b){
	return a.x<b.x;
}
bool cmpy(point a,point b){
	return a.y<b.y;
}
void build(int &o,int l,int r){
	if (l>r) return;
	if (!o) o= ++tot;
	if (l==r){
		a[o]= (node){P[l].x,P[l].y,0,l,r,0,0};
		return;
	}
	double x= Fx(l,r);
	double y= Fy(l,r);
	int mid= (l+r)>>1;
	if (x>=y){
		sort(P+l,P+r+1,cmpx);
		a[o]= (node){P[mid].x,P[mid].y,0,l,r,0,0};
		build(a[o].left,l,mid-1);
		build(a[o].right,mid+1,r);
	}else {
		sort(P+l,P+r+1,cmpy);
		a[o]= (node){P[mid].x,P[mid].y,1,l,r,0,0};
		build(a[o].left,l,mid-1);
		build(a[o].right,mid+1,r);		
	}
}
double dist(point a,point b){
	double x= a.x-b.x,y= a.y-b.y;
	return sqrt(x*x+y*y);
}
void update(int o,point b){
	point p= (point){a[o].x,a[o].y};
	double x= dist(p,b);
	if (x<now){
		now= x;
		ans= p;
	}
}
void find(int o,point b){
	if (!o) return;
	if (a[o].l==a[o].r){
		update(o,b);
		return;
	}
	if (!a[o].split){
		if (b.x<=a[o].x){
			find(a[o].left,b);
			update(o,b);
			if (b.x+now>a[o].x)
				find(a[o].right,b);
		}
		else {
			find(a[o].right,b);
			update(o,b);
			if (b.x-now<=a[o].x)
				find(a[o].left,b);
		}
	}else {
		if (b.y<=a[o].y){
			find(a[o].left,b);
			update(o,b);
			if (b.y+now>a[o].y)
				find(a[o].right,b);
		}
		else {
			find(a[o].right,b);
			update(o,b);
			if (b.y-now<=a[o].y)
				find(a[o].left,b);
		}		
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%lf%lf",&x, &y);
		P[i]= (point){x,y};
	}
	build(root,1,n);
	for (i= 1;i<=m;i++){
		scanf("%lf%lf",&x, &y);
		ans= (point){0,0};
		now= oo;
		find(root,(point){x,y});
		printf("%.2lf %.2lf\n",ans.x, ans.y);
	}return 0;
}
