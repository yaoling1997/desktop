#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-8;
const int maxn= 300001,oo= 1e8;
struct point{
	double x,y;
};
typedef point vec;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
point p[maxn],ch[maxn];
int c[maxn];
double f[maxn],a[maxn],b[maxn],r[maxn];
double s,ans;
int i,j,n;

vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double w(int i,point p){
	return p.x*a[i]+p.y*b[i];
}
bool cmp(point a,point b){return a<b;}
bool cmp1(int i,int j){
	return -a[i]/b[i]>-a[j]/b[j];
}
int convexHull(int n){
	sort(p+1,p+n+1,cmp);
	int i,w= 0,q= 1;
	for (i= 1;i<=n;i++)
		if (dcmp(p[i].y-p[q].y)>=0) q= i;
	for (i= q;i<=n;i++){
		while (w>1&&dcmp(cj(ch[w]-ch[w-1],p[i]-ch[w-1]))>=0) w--;
		ch[++w]= p[i];
	}return w;
}
void cdq(int L,int R){
	if (L==R) return;
	double x,y,Max= -oo;	
	int mid= (L+R)>>1,i,n,j,u;
	cdq(L,mid);
	sort(c+mid+1,c+R+1,cmp1);
	for (i= L;i<=mid;i++){
		x= f[i]/(r[i]*a[i]+b[i]);
		p[i-L+1]= (point){x*r[i],x};
		Max= max(f[i],Max);
	}j= 1;
	n= convexHull(mid-L+1);	
	for (i= mid+1;i<=R;i++){
		u= c[i];y= w(u,ch[j]);
		if (j<n){
			while (j<n){
				x= w(u,ch[j+1]);
				if (x<y) break;
				y= x;j++;
			}
		}
		f[u]= max(f[u],Max);
		f[u]= max(f[u],y);
	}
	sort(c+mid+1,c+R+1);
	cdq(mid+1,R);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %lf",&n, &s);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf %lf",&a[i], &b[i], &r[i]);
		c[i]= i;
	}
	f[1]= s;
	cdq(1,n);
	for (i= 1;i<=n;i++)
		ans= max(ans,f[i]);
	printf("%.3lf",ans);
	return 0;
}
