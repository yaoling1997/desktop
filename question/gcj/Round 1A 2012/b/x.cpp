#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
int a[maxn],b[maxn],vis[maxn];
int T,i,j,n,ans,now,bl,x,y,z;
void init(){
	memset(vis,0,sizeof(vis));
	ans= now= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);		
		scanf("%d",&n);
		init();
		for (i= 1;i<=n;i++)
			scanf("%d%d",&a[i], &b[i]);
		bl= 1;
		for (;bl;){
			bl= 0;
			x= y= z= 0;
			for (i= 1;i<=n;i++){
				if (vis[i]==2) continue;
				if (vis[i]==1){
					if (b[i]<=now&&(!x||b[i]<b[x]))
						x= i;
				}
				if (vis[i]==0){
					if (a[i]<=now&&(!y||b[i]>b[y]))
						y= i;
					if (b[i]<=now&&!z)
						z= i;
				}
			}
			if (z){
				vis[z]= 2;
				now+= 2;
				ans++;
				bl= 1;
			}else if (x){
				vis[x]= 2;
				now++;
				ans++;
				bl= 1;
			}else if (y){
				vis[y]= 1;
				now++;
				ans++;
				bl= 1;
			}
		}
		bl= 1;
		for (i= 1;i<=n;i++)
			if (vis[i]!=2){
				bl= 0;
				break;
			}
		if (bl)
			printf("%d\n",ans);
		else printf("Too Bad\n");
	}return 0;
}
