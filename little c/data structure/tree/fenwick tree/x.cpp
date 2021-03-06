#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=110000;
int n,i,j,x,y,ans;
int c[maxn],a[maxn];
int lowbit(int o){
	return o&(-o);
}
void add(int o,int x){
	while (o<=n){
		c[o]+=x;
		o+=lowbit(o);
	}		
}
int sum(int o){
	int s= 0;
	while (o>0){
		s+=c[o];
		o-=lowbit(o);
	}
	return s;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
		c[i]=a[i]-a[i-lowbit(i)];
	}
	int m;
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d\n",&x,&y);
			add(x,y);
		}else {
			scanf("%d %d\n",&x,&y);
			printf("%d\n",sum(y)-sum(x-1));
		}
	}
	return 0;	
}
