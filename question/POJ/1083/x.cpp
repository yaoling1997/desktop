#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
struct node{
	int l,r;
	bool operator <(const node &a)const{
		return l<a.l || (l==a.l && r<a.r);
	}
}a[maxn];
bool use[maxn];
int x,y,i,n,T,bl,now,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		ans= 0;
		scanf("%d",&n);
		for (i= 1;i<=n;i++){
			scanf("%d %d",&x, &y);
			if (x>y) swap(x,y);
			a[i]= (node){(x+1)/2,(y+1)/2};
			use[i]= 0;
		}
		sort(a+1,a+n+1);
		do{
			bl= now= 0;
			for (i= 1;i<=n;i++)
				if (!use[i]&&a[i].l>now){
					bl= 1;
					use[i]= 1;
					now= a[i].r;
				}
			if (bl) ans+= 10;
		}while (bl);
		printf("%d\n",ans);
	}return 0;
}
