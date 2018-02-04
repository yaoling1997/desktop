#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn= 80,oo= 1e9;
struct point{
	int x,y;
};
int lx[maxn],ly[maxn],S[maxn],T[maxn];
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],d[maxn];
int i,j,TT,n,ans;
bool match(int o){
	S[o]= 1;int i;
	for (i= 1;i<=n;i++)
		if (lx[o]+ly[i]==c[o][i]){
			if (!T[i]){
				T[i]= 1;
				if (!d[i]||match(d[i])){
					d[i]= o;
					return 1;
				}
			}
		}return 0;
}
void update(){
	int a= oo,i,j;
	for (i= 1;i<=n;i++)
		if (S[i])
			for (j= 1;j<=n;j++)
				if (!T[j])
					a= min(a,lx[i]+ly[j]-c[i][j]);
	for (i= 1;i<=n;i++){
		if (S[i]) lx[i]-= a;
		if (T[i]) ly[i]+= a;
	}
}
point km(){
	int i,j,sum1= 0,sum2= 0;
	for (i= 1;i<=n;i++){
		d[i]= ly[i]= 0;
		lx[i]= -oo;
		for (j= 1;j<=n;j++)
			lx[i]= max(lx[i],c[i][j]);
	}
	for (i= 1;i<=n;i++)
		for(;;){
			for (j= 1;j<=n;j++) S[j]= T[j]= 0;
			if (match(i)) break;
			else update();
		}
	for (i= 1;i<=n;i++)
		sum1+= a[d[i]][i],sum2+= b[d[i]][i];
	ans= min(ans,sum1*sum2);
	return (point){sum1,sum2};
}
void work(point p1,point p2){
	int A= p2.y-p1.y,B= p1.x-p2.x,C= p2.x*p1.y-p1.x*p2.y,i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[i][j]= A*a[i][j]+B*b[i][j];
	point p= km();
	if (A*p.x+B*p.y+C<=0) return;
	work(p1,p);work(p,p2);
}
void get(){
	ans= oo;
	point p1,p2;
	int i,j;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[i][j]= -a[i][j];
	p1= km();
	for (i= 1;i<=n;i++)
		for (j= 1;j<=n;j++)
			c[i][j]= -b[i][j];
	p2= km();
	work(p1,p2);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&TT);
	for (int a1= 1;a1<=TT;a1++){
		scanf("%d",&n);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for (i= 1;i<=n;i++)
			for (j= 1;j<=n;j++)
				scanf("%d",&b[i][j]);
		get();
		printf("%d\n",ans);
	}return 0;
}
