#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 3001,oo= 1e8;
const double eps= 1e-8,PI= 2*acos(0.0);
struct point{
	double x,y;
};
typedef point vec;
typedef point seg;
struct circle{
	point c;
	double r;
	point getpoint(double a){
		return (point){c.x+cos(a),c.y+sin(a)};
	}
};
vector<seg> sol;
circle C[maxn];
double x,y,z,ans;
int bl,n,i,j,len;
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
vec rot(vec a,double r){
	vec c;
	c.x= a.x*cos(r)-a.y*sin(r);
	c.y= a.x*sin(r)+a.y*cos(r);
	return c;
}
double length(vec a){return sqrt(dj(a,a));}
double polarAngle(vec a){return atan2(a.y,a.x);}
int cci(circle c1,circle c2){
	point o1= c1.c,o2= c2.c;
	double r1= c1.r,r2= c2.r,d= length(o1-o2);
	if (!dcmp(d)){
		if (dcmp(r1-r2)<=0) return -1;
		else return 0;
	}
	if (dcmp(fabs(r1-r2)-d)>0||dcmp(r1+r2-d)<0){
		if (dcmp(fabs(r1-r2)-d)>0&&r1<r2) return -1;
		return 0;
	}
	double base= polarAngle(o2-o1);
	double da= acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	r1= base-da;r2= base+da;
	if (dcmp(r1+PI)<0){
		sol.push_back((seg){r1+2*PI,PI});
		sol.push_back((seg){-PI,r2});
	}else if (dcmp(r2-PI)>0){
		sol.push_back((seg){-PI,r2-2*PI});
		sol.push_back((seg){r1,PI});
	}else sol.push_back((seg){r1,r2});
	return 2;
}
bool cmp(seg a,seg b){return a<b;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lf %lf %lf",&z, &x, &y);
		C[i]= (circle){x,y,z};		
	}
	for (i= 1;i<=n;i++){
		sol.clear();bl= 0;
		for (j= i+1;j<=n;j++){
			bl= cci(C[i],C[j]);
			if (bl==-1) break;
		}
		if (bl!=-1){
			double r= C[i].r,sum= 0;
			sort(sol.begin(),sol.end(),cmp);
			x= -PI;len= sol.size();
			for (j= 0;j<len;j++){
				x= max(x,sol[j].x),y= sol[j].y;
				if (dcmp(y-x)>0){
					sum+= (y-x)*r;
					x= y;
				}
			}
			ans+= 2*r*PI-sum;
		}
	}
	printf("%.3lf\n",ans);
	return 0;
}
