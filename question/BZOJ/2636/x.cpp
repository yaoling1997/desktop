#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const double eps= 1e-8;
const int maxn= 2000000,maxl= 100,maxm= 30000;
struct point{
	double x,y;
};
typedef point vec;
point p[maxn];
vec VV[maxn],V[maxn];
double rad[maxn];
int size[maxn],left[maxn],right[maxn],c[maxm],bc[maxn];
char s[maxl];
vec v,v2;
int i,n,m,x,y,tot,time,O,o;
double xx,yy,Rad;
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0 ? -1:1;
}
vec operator +(vec a,vec b){return (vec){a.x+b.x,a.y+b.y};}
vec operator -(vec a,vec b){return (vec){a.x-b.x,a.y-b.y};}
vec operator *(double t,vec a){return (vec){a.x*t,a.y*t};}
vec operator /(vec a,double t){return (vec){a.x/t,a.y/t};}
bool operator <(vec a,vec b){return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);}
bool operator ==(vec a,vec b){return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
vec rot(vec a,double r){return (vec){a.x*cos(r)-a.y*sin(r),a.x*sin(r)+a.y*cos(r)};}
double length(vec a){return sqrt(dj(a,a));}
void copy(int O,int o){
	left[O]= left[o];
	right[O]= right[o];
}
void build(int &o,int l,int r){
	if (!o) o= ++tot;
	if (l+1<r){
		int mid= (l+r)>>1;
		build(left[o],l,mid);
		build(right[o],mid,r);
	}else VV[o]= p[l];
}
void pushdown(int o,int O){
	int q1,q2,p1,p2;
	q1= left[O]= ++tot;q2= right[O]= ++tot;
	p1= left[o];p2= right[o];
	copy(q1,p1);copy(q2,p2);
	bc[q1]= bc[p1];bc[q2]= bc[p2];
	V[q1]= rot(V[p1],rad[O]);
	V[q2]= rot(V[p2],rad[O]);
	VV[q1]= VV[p1];VV[q2]= VV[p2];
	rad[q1]= rad[p1];
	rad[q2]= rad[p2];
	if (bc[O]){
		V[q1]= V[q2]= VV[q1]= VV[q2]= (vec){0,0};
		rad[q1]= rad[q2]= 0;
		bc[q1]= bc[q2]= 1;
	}
	V[q1]= V[q1]+V[O];
	V[q2]= V[q2]+V[O];
	rad[q1]+= rad[O];
	rad[q2]+= rad[O];
	V[O]= (vec){0,0};
	rad[O]= 0;bc[O]= 0;
}
void change1(int o,int O,int l,int r,int L,int R){
	if (l>=L&&r<=R){
		V[O]= V[O]+v;
		copy(O,o);
		return;		
	}
	if (l+1<r)	pushdown(o,O);
	int mid= (l+r)>>1;
	if (L<mid) change1(left[o],left[O],l,mid,L,R);
	if (mid<R) change1(right[o],right[O],mid,r,L,R);
}
void change2(int o,int O,int l,int r,int L,int R){
	if (l>=L&&r<=R){
		V[O]= rot(V[O],xx);
		rad[O]+= xx;
		if (!bc[O])	bc[O]= bc[o];
		copy(O,o);		
		return;
	}
	if (l+1<r)	pushdown(o,O);	
	int mid= (l+r)>>1;
	if (L<mid) change2(left[o],left[O],l,mid,L,R);
	if (mid<R) change2(right[o],right[O],mid,r,L,R);	
}
void change3(int o,int O,int l,int r,int L,int R){
	if (l>=L&&r<=R){
		bc[O]= 1;
		rad[O]= 0;		
		VV[O]= V[O]= (vec){0,0};
		copy(O,o);		
		return;
	}
	if (l+1<r)	pushdown(o,O);	
	int mid= (l+r)>>1;
	if (L<mid) change3(left[o],left[O],l,mid,L,R);
	if (mid<R) change3(right[o],right[O],mid,r,L,R);	
}
void ask(int o,int l,int r,int x){
	if (l+1==r){
		v2= VV[o];
		v= V[o];
		Rad= rad[o];
		return;
	}
	int mid= (l+r)>>1;	
	if (x<mid) ask(left[o],l,mid,x);
	else ask(right[o],mid,r,x);
	if (bc[o]){
		v2= v= (vec){0,0};
		Rad= 0;
	}
	v= rot(v,rad[o]);
	v= v+V[o];
	Rad+= rad[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf",&xx, &yy);
		p[i]= (point){xx,yy};
	}
	build(c[time= 1],1,n+1);
	scanf("%d",&m);
	for (int a1= 1;a1<=m;a1++){
		scanf("%s",s+1);
		if (s[1]=='M'){
			scanf("%d %d %lf %lf",&x, &y, &xx, &yy);
			v= (vec){xx,yy};
			c[++time]= ++tot;
			O= c[time];o= c[time-1];
			V[O]= V[O]+V[o];
			rad[O]+= rad[o];
			bc[O]= bc[O]||bc[o];
			VV[O]= VV[o];			
			change1(c[time-1],c[time],1,n+1,x,y+1);			
		}else if (s[1]=='P'){
			scanf("%d %d %lf",&x, &y, &xx);
			c[++time]= ++tot;
			O= c[time];o= c[time-1];			
			V[O]= V[O]+V[o];
			rad[O]+= rad[o];
			bc[O]= bc[O]||bc[o];
			VV[O]= VV[o];
			change2(c[time-1],c[time],1,n+1,x,y+1);
		}else if (s[1]=='L'){
			scanf("%d %d",&x, &y);
			c[++time]= ++tot;
			O= c[time];o= c[time-1];			
			V[O]= V[O]+V[o];
			rad[O]+= rad[o];
			bc[O]= bc[O]||bc[o];
			VV[O]= VV[o];			
			change3(c[time-1],c[time],1,n+1,x,y+1);
		}else if (s[1]=='C'){
			scanf("%d",&x);
			time-= x;
		}else if (s[1]=='R'){
			scanf("%d",&x);
			time+= x;
		}else {
			scanf("%d",&x);
			ask(c[time],1,n+1,x);
			v2= rot(v2,Rad);
			v2= v2+v;
			if (!dcmp(v2.x)) v2.x= 0;
			if (!dcmp(v2.y)) v2.y= 0;
			printf("%.10lf %.10lf\n",v2.x, v2.y);
		}
	}
	return 0;
}
