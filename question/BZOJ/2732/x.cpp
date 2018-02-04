#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define double long double
using namespace std;
const int maxn= 600001;
const double eps= 1e-12,pi= 3.141592654;
struct point{
	double x,y;
};
struct node{
	int x,y1,y2;
};
typedef point vec;
struct line{
	point p;
	vec v;
	double ang;
	void askang(){ang= atan2(v.y,v.x);}
};
double dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
node a[maxn];
line l[maxn],q[maxn];
point p[maxn];
int n,L,R,i,top;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<eps || (!dcmp(a.x-b.x) && dcmp(a.y-b.y)<0);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
point jd(line a,line b){
	vec u= a.p-b.p;
	return a.p+cj(b.v,u)/cj(a.v,b.v)*a.v;
}
bool onleft(line a,point p){
	return dcmp(cj(a.v,p-a.p))>0;
}
void addline(int o){
	int i;point a1,a2;top= 0;
	for (i= 1;i<=o;i++){
		double x= a[i].x,y1= a[i].y1,y2= a[i].y2;
		a1.x= 1; a1.y= (y1-x*x)/x; a2.x= 2; a2.y= (y1-2*x*x)/x;
		l[++top].p= a1;l[top].v= a2-a1;
		l[top].askang();
		a1.x= 2;a1.y= (y2-2*x*x)/x;a2.x= 1;a2.y= (y2-x*x)/x;		
		l[++top].p= a1;l[top].v= a2-a1;
		l[top].askang();
	}top++;
	l[top].p.x= l[top].p.y= 0;l[top].v.y= 1;l[top].v.x= 0;l[top].askang();
}
bool cmpl(line a,line b){return a.ang<b.ang;}
int hpi(int n){
	sort(l+1,l+n+1,cmpl);
	int first= 1,last= 1,i;
	q[1]= l[1];
	for (i= 2;i<=n;i++){
		while (first<last && !onleft(l[i],p[last-1])) last--;
		while (first<last && !onleft(l[i],p[first])) first++;
		q[++last]= l[i];
		if (!dcmp(cj(q[last].v,q[last-1].v))){
			last--;
			if (first<last && onleft(q[last],l[i].p)) q[last]= l[i];
		}
		if (first<last) p[last-1]= jd(q[last],q[last-1]);
	}
	while (first<last && !onleft(q[first],p[last-1])) last--;
	if (last-first+1<=2){
		return 0;
	}
	return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d %d %d",&a[i].x,&a[i].y1, &a[i].y2);
	if (n==1){
		printf("%d",1);
		return 0;
	}
	L= 0;R= n+1;
	while (L+1<R){
		int mid= (L+R)>>1;
		addline(mid);
		int m= hpi(top);
		if (m) L= mid;
		else R= mid;
	}
	printf("%d",L);
	return 0;
}
