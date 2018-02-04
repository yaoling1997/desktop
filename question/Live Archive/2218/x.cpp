#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-10,PI= acos(-1);
const int maxn= 2e4;
struct point{
	double x,y;
};
typedef point vec;
struct line{
	point p;
	vec v;
	double ang;
	void getang(){
		ang= atan2(v.y,v.x);
	}
	bool operator <(const line a)const{
		return ang<a.ang;
	}
};
line q[maxn],l[maxn];
point p[maxn],poly[maxn];
double V[maxn],U[maxn],W[maxn];
int h[maxn];
//point p;
vec v;
double a,b,c,k= 1;
int i,j,ok,n,m;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double length(vec a){return sqrt(dj(a,a));}
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
point jd(line a,line b){
	vec u= a.p-b.p;
	double t= cj(b.v,u)/cj(a.v,b.v);
	return a.p+t*a.v;
}
bool onleft(line a,point p){
	return dcmp(cj(a.v,p-a.p))>0;
}
int hpi(int n){
	sort(l+1,l+n+1);
	int i,first= 1,last= 1;
	q[1]= l[1];
	h[1]= 1;
	for (i= 2;i<=n;i++){
		while (first<last&&!onleft(l[i],p[last-1])) last--;
		while (first<last&&!onleft(l[i],p[first])) first++;
		q[++last]= l[i];
		h[last]= i;
		if (!dcmp(cj(q[last].v,q[last-1].v))){
			last--;
			if (onleft(q[last],l[i].p)){
				q[last]= l[i];
				h[last]= i;
			}
		}
		p[last-1]= jd(q[last-1],q[last]);
	}
	while (first+1<last&&!onleft(q[first],p[last-1])) last--;
	p[last]= jd(q[first],q[last]);
	if (last-first<=1){
		for (i= 1;i<=n;i++){
			if (i==h[first]||i==h[last])
				continue;
			if (!onleft(l[i],p[last])) return 0;
		}
		return 1;
	}else return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		for (i= 1;i<=n;i++)
			scanf("%lf%lf%lf",&V[i], &U[i], &W[i]);
		for (i= 1;i<=n;i++){
			ok= 1;
			for (j= 1;j<=n;j++){
				if (i==j) continue;
				if (V[i]<=V[j]&&U[i]<=U[j]&&W[i]<=W[j]){
					ok= 0;
					break;
				}
			}
			if (!ok) printf("No\n");
			else {
				point p;
				m= 0;
				for (j= 1;j<=n;j++){
					if (i==j) continue;
					if (V[j]<=V[i]&&U[j]<=U[i]&&W[j]<=W[i]) continue;
					a= k/V[i]-k/V[j]+k/W[j]-k/W[i];
					b= k/U[i]-k/U[j]+k/W[j]-k/W[i];
					c= k/W[i]-k/W[j];
					v= (vec){-b,a};
					if (fabs(a)>fabs(b))
						p= (point){-c/a,0};
					else p= (point){0,-c/b};
					l[++m]= (line){p,v,0};
				}
				a= k;b= k;c= -k;
				v= (vec){-b,a};
				p= (point){-c/a,0};
				l[++m]= (line){p,v,0};
				p= (point){0,0};
				v= (vec){0,-1};
				l[++m]= (line){p,v,0};
				v= (vec){1,0};
				l[++m]= (line){p,v,0};
				for (j= 1;j<=m;j++)
					l[j].getang();
				ok= hpi(m);
				if (ok) printf("Yes\n");
				else printf("No\n");
			}
		}
	}return 0;
}
