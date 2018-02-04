#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
struct N{
	int r,t;
}sta[maxn];
int a[maxn],b[maxn];
int n,m,i,j,la,x,y,p,q;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]= a[i];
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		while (la&&sta[la].r<=y) la--;
		if (la&&sta[la].t==x) continue;
		sta[++la]= (N){y,x};
	}
	sta[la+1]= (N){0,0};
	p= 1;q= sta[1].r;
	sort(b+1,b+sta[1].r+1);
	for (i= 2;i<=la+1;i++)
		if (sta[i-1].t==1)
			for (j= sta[i-1].r;j>sta[i].r;j--){
				a[j]= b[q];
				q--;
			}
		else for (j= sta[i-1].r;j>sta[i].r;j--){
				 a[j]= b[p];
				 p++;
			}
	for (i= 1;i<=n;i++)
		printf("%d%c",a[i],i<n?' ':'\n');
}
