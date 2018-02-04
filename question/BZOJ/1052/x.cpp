#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 30001,oo= 1e9+1;
struct point{
	double x,y;
};
point p[maxn];
int b[maxn];
double x,y;
int i,n,l,r;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
bool isq(point a,point b,point p){
	double x1,x2,y1,y2;
	x1= min(a.x,b.x);x2= max(a.x,b.x);
	y1= min(a.y,b.y);y2= max(a.y,b.y);
	if (dcmp(p.x-x1)>=0&&dcmp(p.x-x2)<=0)
		if (dcmp(p.y-y1)>=0&&dcmp(p.y-y2)<=0) return 1;
	return 0;
}
bool right(int o,int l,int s){
	if (o<=3){
		point p1,p2;
		double x1= oo,x2= -oo,y1= oo,y2= -oo;
		int sta[maxn]= {0};
		int i,top= 0,bl;
		for (i= 1;i<=n;i++)
			if (!b[i]){
				x1= min(x1,p[i].x);
				x2= max(x2,p[i].x);
				y1= min(y1,p[i].y);
				y2= max(y2,p[i].y);
			}
		p1= (point){x1,y1};
		p2= (point){x1+l,y1+l};
		for (i= 1;i<=n;i++)
			if (!b[i])
				if (isq(p1,p2,p[i])){
					sta[++top]= i;
					b[i]= 1;
				}
		bl= right(o+1,l,s+top);
		while(top) b[sta[top--]]= 0;
		if (bl) return 1;
		p1= (point){x1,y2-l};
		p2= (point){x1+l,y2};
		for (i= 1;i<=n;i++)
			if (!b[i])
				if (isq(p1,p2,p[i])){
					sta[++top]= i;
					b[i]= 1;
				}
		bl= right(o+1,l,s+top);
		while(top) b[sta[top--]]= 0;
		if (bl) return 1;
		p1= (point){x2-l,y1};
		p2= (point){x2,y1+l};
		for (i= 1;i<=n;i++)
			if (!b[i])
				if (isq(p1,p2,p[i])){
					sta[++top]= i;
					b[i]= 1;
				}
		bl= right(o+1,l,s+top);
		while(top) b[sta[top--]]= 0;
		if (bl) return 1;
		p1= (point){x2-l,y2-l};
		p2= (point){x2,y2};
		for (i= 1;i<=n;i++)
			if (!b[i])
				if (isq(p1,p2,p[i])){
					sta[++top]= i;
					b[i]= 1;
				}
		bl= right(o+1,l,s+top);
		while(top) b[sta[top--]]= 0;
		if (bl) return 1;		
	}else if (s>=n) return 1;
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);	
	for (i= 1;i<=n;i++){
		scanf("%lf %lf",&x, &y);
		p[i]= (point){x,y};
	}
	l= -1;r= oo;
	while (l+1<r){
		int mid= (l+r)>>1;
		if (right(1,mid,0)) r= mid;
		else l= mid;
	}
	printf("%d\n",r);
	return 0;
}
