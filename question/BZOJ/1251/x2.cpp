#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn= 550000;
long long a[maxn][4],c[maxn];
long long ans;
int i,n,x,y,z,q;
long long ad(int o)
{
	return a[o][3]+a[o][0];
}
void build(int o,int l,int r)
{
	int mid= (l+r)>>1;
	a[o][1]= l;
	a[o][2]= r;
	if ((r-l)>1){
		build(2*o,l,mid);
		build(2*o+1,mid,r);
		a[o][3]= max(a[2*o][3],a[2*o+1][3]);
	}else a[o][3]= c[l];
}
void change(int o)
{
	if (a[o][1]>=x && a[o][2]<=y){
		a[o][0]+=z;
		return;
	}
	a[2*o][0]+= a[o][0];
	a[2*o+1][0]+= a[o][0];
	int mid= (a[o][1]+a[o][2])>>1;
	if (x<mid) change(2*o);
	if (y>mid) change(2*o+1);
	a[o][3]= ad(2*o);
	a[o][3]= max(a[o][3],ad(2*o+1));
	a[o][0]= 0;
}
void maxi(int o)
{
	if (a[o][1]>=x && a[o][2]<=y){
		ans=max(ans,ad(o));
		return;
	}
	a[2*o][0]+= a[o][0];
	a[2*o+1][0]+= a[o][0];
	int mid= (a[o][1]+a[o][2])>>1;
	if (x<mid) maxi(2*o);
	if (y>mid) maxi(2*o+1);
	a[o][3]= ad(2*o);
	a[o][3]= max(a[o][3],ad(2*o+1));
	a[o][0]= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d\n",&n, &q);
	build(1,1,n+1);
	for (i= 1;i<=q;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d %d\n",&x,&y,&z);
			y++;
			change(1);
		}else {
			ans= -99999999;
			scanf("%d %d\n",&x,&y);
			y++;
			maxi(1);
			printf("%lld\n",ans);
		}
	}
	return 0;	
}
