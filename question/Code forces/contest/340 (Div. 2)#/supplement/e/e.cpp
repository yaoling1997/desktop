#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5,maxm= 2e6+10;
struct node{
	int l,r,h;
}Q[maxn];
ll ans[maxn],cnt;
int b[maxm],a[maxn],s[maxn];
int n,m,i,j,k,x,y,M,l,r,I,Max;
bool cmpl(node a,node b){
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
bool cmpr(node a,node b){
	return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &m, &k);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]= a[i]^s[i-1];
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d",&Q[i].l, &Q[i].r);
		Q[i].h= i;
	}
	M= sqrt(m)+0.1;
	sort(Q+1,Q+m+1,cmpl);
	l= 0,r= 0;
	cnt= 0;
	b[0]= 1;
	for (I= 1;I<=m;I+= M){
		Max= min(I+M-1,m);
		sort(Q+I,Q+Max+1,cmpr);
		for (j= I;j<=Max;j++){
			x= Q[j].l,y= Q[j].r;
			x--;
			if (x<l){
				for (i= l-1;i>=x;i--){
					cnt+= b[s[i]^k];
					b[s[i]]++;
				}
			}else {
				for (i= l;i<x;i++){
					b[s[i]]--;
					cnt-= b[s[i]^k];
				}
			}
			if (y<r){
				for (i= r;i>y;i--){
				b[s[i]]--;
				cnt-= b[s[i]^k];
				}
			}else {
				for (i= r+1;i<=y;i++){
					cnt+= b[s[i]^k];
					b[s[i]]++;
				}
			}
			l= x;
			r= y;
			ans[Q[j].h]= cnt;
		}
	}
	for (i= 1;i<=m;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}
