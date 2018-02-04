#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 110000;
long long a[maxn][3],c[maxn];
int i,n,x,y,z,q;
void build(int o,int l,int r){
	int mid= (l+r)>>1;
	a[o][1]= l;
	a[o][2]= r;
	if ((r-l)>1){
		build(2*o,l,mid);
		build(2*o+1,mid,r);
	}
}
void add(int o){
	if (a[o][1]>=x && a[o][2]<=y){
		a[o][0]+=z;
		return;
	}
	a[2*o][0]+= a[o][0];
	a[2*o+1][0]+= a[o][0];
	a[o][0]= 0;
	int mid= (a[o][1]+a[o][2])>>1;
	if (x<mid) add(2*o);
	if (y>mid) add(2*o+1);
}
void find(int o){
	if (a[o][1]>=x && a[o][2]<=y){
		printf("%lld\n",a[o][0]+c[a[o][1]]);
		return;
	}
	a[2*o][0]+= a[o][0];
	a[2*o+1][0]+= a[o][0];
	a[o][0]= 0;
	int mid= (a[o][1]+a[o][2])>>1;
	if (x<mid) find(2*o);
	if (y>mid) find(2*o+1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld",&c[i]);
	build(1,1,n+1);
	scanf("%d\n",&q);
	for (i= 1;i<=q;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d %d\n",&x,&y,&z);
			y++;
			add(1);
		}else{
			scanf("%d\n",&x);
			y= x+1;
			find(1);			
		}
	}
	return 0;	
}
