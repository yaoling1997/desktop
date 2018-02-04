#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn= 500001;
struct node{
	double v;
	int s;
};
node a[maxn];
int x,y,n,m,i;
int count(int o,int l,int r,double d){
	if (l+1==r)
		return a[o].v>d;	
	int mid= (l+r)>>1;
	if (a[2*o].v<=d) return count(2*o+1,mid,r,d);
	return count(2*o,l,mid,d)+a[o].s-a[2*o].s;
}
void update(int o,int l,int r,double d){
	int mid= (l+r)>>1;
	a[o].v= max(a[2*o].v,a[2*o+1].v);
	a[o].s= a[2*o].s+count(2*o+1,mid,r,a[2*o].v);
}
void change(int o,int l,int r,int v,double d){
	if (l+1==r){
		a[o].v= d;
		a[o].s= 1;
		return;
	}
	int mid= (l+r)>>1;
	if (v<mid) change(2*o,l,mid,v,d);
	else change(2*o+1,mid,r,v,d);
	update(o,l,r,d);
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		//scanf("%d %d",&x, &y);
		x= getint();y= getint();
		change(1,1,n+1,x,(double)y/x);
		printf("%d\n",a[1].s);
	}
	return 0;
}
