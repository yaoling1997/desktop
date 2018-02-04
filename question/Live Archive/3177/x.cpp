#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 2e5;
int c[maxn],left[maxn],right[maxn];
int n,i,ans,L,R;
int ok(int x){
	left[1]= c[1];right[1]= 0;
	int i;
	for (i= 2;i<=n;i++){
		if (i&1){
			right[i]= min(x-c[1]-right[i-1],c[i]);
			left[i]= c[i]-right[i];
		}else {
			left[i]= min(c[1]-left[i-1],c[i]);
			right[i]= c[i]-left[i];
		}
	}return !left[n];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF&&n){
		ans= L= R= 0;L--;
		for (i= 1;i<=n;i++){
			scanf("%d",&c[i]);
			R= max(R,3*c[i]);
		}
		if (n==1){
			printf("%d\n",c[1]);
			continue;
		}
		c[n+1]= c[1];
		for (i= 1;i<=n;i++)	L= max(L,c[i]+c[i+1]);		
		if ((n&1)==0){
			for (i= 1;i<=n;i++)	ans= max(ans,c[i]+c[i+1]);
		}else {L--;
			while (L+1<R){
				int mid= (L+R)>>1;
				if (ok(mid)) R= mid;
				else L= mid;
			}ans= R;
		}
		printf("%d\n",ans);
	}return 0;
}
