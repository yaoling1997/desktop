#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ld eps= 1e-15,PI= acos(-1),little= 1e-13;
const int maxn= 2e2;
struct point{
	ld x,y;
};
struct circle{
	point c;
	ld r;
	point getpoint(ld a){
		return (point){c.x+r*cos(a),c.y+r*sin(a)};
	}
}C[maxn],p[maxn];
typedef point vec;
vector<point> sol;
ld x,y,z;
int b[maxn];
int ans,i,j,n;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(ld t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,ld t){a.x/= t;a.y/= t;return a;}
int dcmp(ld x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0||(!dcmp(a.x-b.x)&&dcmp(a.y-b.y)<0);
}
bool operator ==(vec a,vec b){
	return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
}
ld dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
ld cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
ld length(vec a){return sqrt(dj(a,a));}
ld polarAngle(vec a){
	return atan2(a.y,a.x);
}
vec rot(vec a,ld r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
void init(){
	memset(b,0,sizeof(b));
	ans= 0;
}
bool cmp(point a,point b){
	return polarAngle(a-C[i].c)<polarAngle(b-C[i].c);
}
int cci(circle c1,circle c2){
	if (c1.r<c2.r) swap(c1,c2);
	point o1= c1.c,o2= c2.c;
	ld r1= c1.r,r2= c2.r,d= length(o2-o1);
	if (!dcmp(d)){
		if (!dcmp(r1-r2)) return -1;
		return 0;
	}
	if (dcmp(r1-r2-d)>0) return 0;
	if (dcmp(r1+r2-d)<0) return 0;
	ld base= polarAngle(o2-o1);
	if (!dcmp(r1-r2-d)||!dcmp(r1+r2-d)){
		sol.push_back(c1.getpoint(base));
		return 1;
	}
	ld da= acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	sol.push_back(c1.getpoint(base+da));
	sol.push_back(c1.getpoint(base-da));
	return 2;
}
bool pic(point p,circle c){
	return length(p-c.c)-c.r<0;
}
void update(point a){
	int i;
	for (i= n;i>0;i--)
		if (pic(a,C[i])){
			ans+= 1-b[i];
			b[i]= 1;
			return;
		}
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%Lf%Lf%Lf",&x, &y, &z);
			C[i]= (circle){(point){x,y},z};
		}
		for (i= 1;i<=n;i++){
			sol.clear();
			sol.push_back(C[i].getpoint(0));
			sol.push_back(C[i].getpoint(PI));
			for (j= 1;j<=n;j++)
				cci(C[i],C[j]);
			sort(sol.begin(),sol.end(),cmp);
			sol.push_back(sol[0]);
			int len= sol.size();
			for (j= 1;j<len;j++){
				x= polarAngle(sol[j-1]-C[i].c);
				y= polarAngle(sol[j]-C[i].c);
				point m= C[i].getpoint((x+y)/2);
				vec v= m-C[i].c;
				v= v/length(v);
				update(m+little*v);
				update(m-little*v);
			}
		}
		printf("%d\n",ans);
	}return 0;
}
