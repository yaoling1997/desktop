#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 300001;
struct node{
	int pos,s;
};
vector<node> b[maxn];
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
	for (i= 1;i<=n;i++){
		b[top].push_back(c[i]);
		if (b[top].size()==size) top++;
	}
	if (!b[top].size()) top--;
	scanf("%d",&q);
	for (t= 1;t<=q;t++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);x++;ans= 0;
			while (x<=n){
				int b1= (x-1)/size+1,a1= (x-1)%size;
				ans+= b[b1][a1].s;
				x= b[b1][a1].pos;
			}
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&x, &y);x++;z= x+y;a[x]= y;
			if (z>n) z= n+2*size;
			b1= (x-1)/size+1,a1= (x-1)%size;
			b2= (z-1)/size+1,a2= (z-1)%size;
			int s= 1;
			if(b1==b2){
				s+= b[b2][a2].s;
				z= b[b2][a2].pos;
			}
			b[b1][a1].s= s;
			b[b1][a1].pos= z;
			for (i= a1-1;i>=0;i--){
				k= (b1-1)*size+i+1;b2= k+a[k];
				a2= (b2-1)%size;
				b2= (b2-1)/size+1;
				if (b1==b2){
					b[b1][i].s= b[b2][a2].s+1;
					b[b1][i].pos= b[b2][a2].pos;
				}else {
					b[b1][i].s= 1;
					b[b1][i].pos= k+a[k];
				}
			}
		}
	}
	return 0;
}
