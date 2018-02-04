#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn= 300001;
struct node{
	int pos,s;
};
node c[maxn];
int a[maxn];
int size,i,n,top,x,y,z,ans,q,k,b1,b2,a1,a2,t;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);size= sqrt(n);top= 1;
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= n;i>0;i--){
		x= i+a[i];if (x>n) x= n+2*size;
		b1= (i-1)/size+1;b2= (x-1)/size+1;
		int s= 1;
		while (b1==b2){
			s+= c[x].s;
			x= c[x].pos;
			b2= (x-1)/size+1;
		}
		c[i].pos= x;c[i].s= s;
	}
	scanf("%d",&q);
	for (t= 1;t<=q;t++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);x++;ans= 0;
			while (x<=n){
				ans+= c[x].s;
				x= c[x].pos;
			}
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&x, &y);x++;z= x+y;a[x]= y;
			if (z>n) z= n+2*size;
			b1= (x-1)/size+1;b2= (z-1)/size+1;int s= 1;
			if (b1==b2){
				s+= c[z].s;
				z= c[z].pos;
			}
			c[x].s= s;c[x].pos= z;
			for (i= x-1;(i>0 && (i-1)/size+1==b1);i--){
				a2= i+a[i];b2= (a2-1)/size+1;
				if (b1==b2){
					c[i].s= c[a2].s+1;
					c[i].pos= c[a2].pos;
				}else {
					c[i].s= 1;
					c[i].pos= a2;
				}
			}
		}
	}
	return 0;
}
