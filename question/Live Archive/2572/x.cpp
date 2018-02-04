#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#define double long double
using namespace std;
const int maxn= 3001;
const double eps= 5*1e-14,move= 1e-13,PI= 2*acos(0.0);
struct point{
	double x,y;
};
typedef point vec;
struct circle{
	point c;
	double r;
};
vector<double> sol;
circle C[maxn];
int b[maxn];
double x,y,z;
int ans,n,time,i,j;
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
double polarAngle(vec a){return atan2(a.y,a.x);}
int cci(circle c1,circle c2){
	point o1= c1.c,o2= c2.c;
	double r1= c1.r,r2= c2.r,d= length(o1-o2);
	if (!dcmp(d)){
		if (!dcmp(r1-r2)) return -1;
		return 0;
	}
	if (dcmp(fabs(r1-r2)-d)>0||dcmp(r1+r2-d)<0) return 0;
	double base= polarAngle(o2-o1);
	double da= acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	sol.push_back(base+da);
	if (!dcmp(da)) return 1;
	sol.push_back(base-da);
	return 2;
}
void find(point p){
	int i;
	for (i= n;i>0;i--){
		point o= C[i].c;
		double r= C[i].r,d= length(p-o);
		if (dcmp(d-r)<0){
			b[i]= time;
			return;
		}
	}
}
void init(){	
	time++;
	ans= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%Lf %Lf %Lf",&x, &y, &z);
			C[i]= (circle){x,y,z};
		}
		for (i= 1;i<=n;i++){
			sol.clear();
			for (j= 1;j<=n;j++)
				if (i!=j)
					cci(C[i],C[j]);
			sol.push_back(-PI);
			sol.push_back(PI);
			sort(sol.begin(),sol.end());
			int len= sol.size();
			for (j= 0;j<len-1;j++){
				double mid= (sol[j]+sol[j+1])/2;
				point o= C[i].c;
				for (int side= -1;side<=1;side+= 2){
					double r= C[i].r+side*move;
					point p= (point){o.x+r*cos(mid),o.y+r*sin(mid)};
					find(p);
				}
			}
		}
		for (i= 1;i<=n;i++)
			if (b[i]==time)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
