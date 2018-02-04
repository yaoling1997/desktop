#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 20;
double d[maxn];
int p[maxn],vis[maxn];
int i,j,n= 12;
double x,y,z;
double f1(double x,double y,double z){
	return z*log(y)+log(log(x));
}
double f2(double x,double y,double z){
	return log(y)+log(z)+log(log(x));
}
bool cmp(int a,int b){
	if (vis[a]) return 1;
	if (vis[b]) return 0;
	return d[a]<d[b]||(d[a]==d[b]&&a>b);
}
bool cmp2(int a,int b){
	return d[a]>d[b]||(d[a]==d[b]&&a>b);
}
void print(int o){
	if (o==1) printf("x^y^z");
	if (o==2) printf("x^z^y");
	if (o==3) printf("(x^y)^z");
	if (o==4) printf("(x^z)^y");
	if (o==5) printf("y^x^z");
	if (o==6) printf("y^z^x");
	if (o==7) printf("(y^x)^z");
	if (o==8) printf("(y^z)^x");	
	if (o==9) printf("z^x^y");
	if (o==10) printf("z^y^x");
	if (o==11) printf("(z^x)^y");
	if (o==12) printf("(z^y)^x");		
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for (i= 1;i<=n;i++) p[i]= i;
	scanf("%lf%lf%lf",&x, &y, &z);
	if (x>1||y>1||z>1){
		if (x<=1)
			for (i= 1;i<=4;i++)
				vis[i]= 1;
		else {
			d[1]= f1(x,y,z);
			d[2]= f1(x,z,y);
			d[3]= d[4]= f2(x,y,z);
		}
		if (y<=1)
			for (i= 5;i<=8;i++)
				vis[i]= 1;
		else {
			d[5]= f1(y,x,z);
			d[6]= f1(y,z,x);
			d[7]= d[8]= f2(y,x,z);
		}		
		if (z<=1)
			for (i= 9;i<=12;i++)
				vis[i]= 1;
		else {
			d[9]= f1(z,x,y);
			d[10]= f1(z,y,x);
			d[11]= d[12]= f2(z,x,y);
		}		
		sort(p+1,p+n+1,cmp);
		print(p[n]);
	}else if (x==1||y==1||z==1){
		if (x==1) print(1);
		else if (y==1) print(5);
		else print(9);
	}else {
		d[1]= f1(1/x,y,z);
		d[2]= f1(1/x,z,y);
		d[3]= d[4]= f2(1/x,y,z);
		d[5]= f1(1/y,x,z);
		d[6]= f1(1/y,z,x);
		d[7]= d[8]= f2(1/y,x,z);
		d[9]= f1(1/z,x,y);
		d[10]= f1(1/z,y,x);
		d[11]= d[12]= f2(1/z,x,y);
		sort(p+1,p+n+1,cmp2);
		print(p[n]);		
	}return 0;
}
