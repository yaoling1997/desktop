#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 1e5;
int a[maxn],b[maxn],vis[maxn],sta[maxn];
int p,q,i,now,la,T,n;
void init(){
	memset(vis,0,sizeof(vis));
	now= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int TT= 1;TT<=T;TT++){
		scanf("%d%d%d",&n, &p, &q);
		p++;q++;
		for (i= 1;i<=p;i++) scanf("%d",&a[i]);
		for (i= 1;i<=q;i++) scanf("%d",&b[i]);		
		init();
		for (i= 1;i<=p;i++)
			a[i]= vis[a[i]]= ++now;
		for (i= 1;i<=q;i++)
			b[i]= vis[b[i]];
		sta[la= 0]= 0;
		for (i= 1;i<=q;i++)
			if (sta[la]<b[i])
				sta[++la]= b[i];
			else {
				int l= -1,r= la;
				while (l+1<r){
					int mid= (l+r)>>1;
					if (sta[mid]>=b[i]) r= mid;
					else l= mid;
				}
				sta[r]= b[i];
			}
		printf("Case %d: %d\n",TT, la);
	}return 0;
}
	
