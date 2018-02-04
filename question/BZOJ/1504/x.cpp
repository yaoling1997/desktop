#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 2001;
struct point{
	double x,y;
};
struct seg{
	point a,b;
};
typedef point vec;
typedef point segment;
vector<seg> a[maxn];
double X[maxn],Y[maxn];
segment A[maxn];
seg s1,s2;
point p,q,v;
double L,R,now,t,ans;
int n,w,T,V,i,j,x,y,z,tot,top;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0? -1:1;
}
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
bool onSeg(point a,point b,point p){
	return !dcmp(cj(b-a,p-a))&&dcmp(dj(p-a,p-b))<=0;
}
bool xj(point a1,point a2,point b1,point b2){
	if (onSeg(a1,a2,b1)||onSeg(a1,a2,b2)||onSeg(b1,b2,a1)||onSeg(b1,b2,a2)){
		if (!dcmp(cj(a2-a1,b1-a1))&&!dcmp(cj(a2-a1,b2-a1))) return 0;
		return 1;
	}
	double x1= cj(a2-a1,b1-a1),x2= cj(a2-a1,b2-a1);
	double y1= cj(b2-b1,a1-b1),y2= cj(b2-b1,a2-b1);
	return dcmp(x1*x2)<0&&dcmp(y1*y2)<0;
}
point jd(point p,vec v,point q,vec w){
	vec u= p-q;
	return p+cj(w,u)/cj(v,w)*v;
}
bool cmp(segment a,segment b){return a<b;}
double get(double o){
	point p,q,b= (point){o,-1};
	vec v= (vec){0,10000};
	seg s;
	double re= 0,x;
	int i,j,top= 0;
	for (i= 1;i<=n;i++){
		int len= a[i].size();
		for (j= 0;j<len;j+= 2){
			s= a[i][j];
			if (dcmp(s.a.x-o)<=0&&dcmp(s.b.x-o)>=0){
				p= jd(s.a,s.b-s.a,b,v);
				s= a[i][j+1];
				q= jd(s.a,s.b-s.a,b,v);
				A[++top]= (segment){p.y,q.y};
			}
		}
	}sort(A+1,A+top+1,cmp);
	re= A[1].y-A[1].x;x= A[1].y;
	for (i= 2;i<=top;i++){
		if (A[i].y<x) continue;
		x= max(x,A[i].x);
		re+= A[i].y-x;
		x= A[i].y;
	}return re;
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d",&n, &w, &T, &V);
	for (i= 1;i<=n;i++){
		scanf("%d %d %d",&x, &y, &z);
		p= (point){0,x};v= (vec){0,y};
		if (x==0&&x+y==w) z= 0;
		if (z==0){
			a[i].push_back((seg){p,(point){T+1,x}});
			a[i].push_back((seg){p+v,(point){T+1,x}+v});
		}else {
			now= 0;
			if (z>0&&x+y==w) z= -z;
			else if (z<0&&x==0) z= -z;
			while (now<T){
				if (z>0){
					L= w-(x+y);
					t= abs(L/z);
					q= (point){now+= t,x= w-y};
					a[i].push_back((seg){p,q});
					a[i].push_back((seg){p+v,q+v});
					Y[++top]= now;
				}else {
					L= x;
					t= abs(L/z);
					q= (point){now+= t,x= 0};
					a[i].push_back((seg){p,q});
					a[i].push_back((seg){p+v,q+v});
					Y[++top]= now;
				}
				p= q;
				z= -z;
			}
		}
	}Y[++top]= 0;Y[++top]= T;
	for (i= 1;i<=n;i++){
		int len= a[i].size();
		for (int i1= 0;i1<len;i1++){
			s1= a[i][i1];
			for (j= i+1;j<=n;j++){
				int len= a[j].size();
				for (int j1= 0;j1<len;j1++){
					s2= a[j][j1];
					if (xj(s1.a,s1.b,s2.a,s2.b)){
						p= jd(s1.a,s1.b-s1.a,s2.a,s2.b-s2.a);
						Y[++top]= p.x;
					}
				}
			}
		}
	}
	sort(Y+1,Y+top+1);
	while (Y[top]>T) top--;
	X[++tot]= Y[1];
	for (i= 2;i<=top;i++)
		if (Y[i]-Y[i-1]>eps) X[++tot]= Y[i];
	sort(X+1,X+tot+1);
	L= get(X[1]);
	for (i= 2;i<=tot;i++){
		R= get(X[i]);
		ans+= (L+R)*(X[i]-X[i-1])/2;
		L= R;
	}
	ans= T*w-ans;
	ans*= V;
	printf("%.2lf",ans);
	return 0;
}
