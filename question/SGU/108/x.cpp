#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
struct node{
	int h,v;
}s[maxn];
int ans[maxn],b[200];
int x,y,la,cnt,n,k,i,M= 100,p;
bool cmp(node a,node b){
	return a.v<b.v;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	for (i= 1;i<=k;i++){
		scanf("%d",&x);
		s[i]= (node){i,x};
	}
	sort(s+1,s+k+1,cmp);	
	p= 1;
	for (i= 1;i<=n;i++){
		cnt+= !b[i%M];
		while (p<=k&&s[p].v==cnt){
			ans[s[p].h]= i;
			p++;
		}
		b[i%M]= 0;
		x= y= i;		
		while (x){
			y+= x%10;
			x/= 10;
		}
		if (y<=n) b[y%M]= 1;
	}
	printf("%d\n",cnt);
	for (i= 1;i<=k;i++)
		printf("%d%c",ans[i], i<k?' ':'\n');
	return 0;
}
