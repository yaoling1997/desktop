#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn= 3001;
const double eps = 1e-8;
struct point{
	double x,y;
};
typedef point vec;
vec operator +(vec a,vec b){a.x+= b.x;a.y+= b.y;return a;}
vec operator -(vec a,vec b){a.x-= b.x;a.y-= b.y;return a;}
vec operator *(double t,vec a){a.x*= t;a.y*= t;return a;}
vec operator /(vec a,double t){a.x/= t;a.y/= t;return a;}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
bool operator <(vec a,vec b){
	return dcmp(a.x-b.x)<0 || (!dcmp(a.x-b.x) && dcmp(a.y-b.y)<0);}
double dj(vec a,vec b){return a.x*b.x+a.y*b.y;}
double cj(vec a,vec b){return a.x*b.y-a.y*b.x;}
point pn[maxn],p;
int n,i;
bool ipos(point a,point b,point p){
	return !dcmp(cj(b-a,p-a)) && dcmp(dj(p-a,p-b))<=0;
}
int ipip(point* pn,int n,point p){
	double k,d1,d2;
	int i,wn= 0;
	pn[n+1]= pn[1];
	for (i= 1;i<=n;i++){
		if (ipos(pn[i],pn[i+1],p)) return -1;
		k= cj(pn[i+1]-pn[i],p-pn[i]);
		d1= pn[i].y-p.y;
		d2= pn[i+1].y-p.y;
		if (k>0 && d1<=0 && d2>0) wn++;
		if (k<0 && d2<=0 && d1>0) wn--;
	}
	pn[n+1]= pn[0];
	return wn!=0;
}//若直接写成return wnl若点是顺时针排列的话会跪
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %lf %lf\n",&n, &p.x, &p.y);
	for (i= 1;i<=n;i++)
		scanf("%lf %lf\n",&pn[i].x, &pn[i].y);
	int ans= ipip(pn,n,p);
	if (ans==1) printf("yes!");
	else if (ans==0) printf("no!");
	else printf("online!");
	return 0;
}
