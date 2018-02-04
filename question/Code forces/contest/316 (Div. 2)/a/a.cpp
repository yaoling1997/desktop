#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
int a[maxn];
int n,m,i,j,x,p,q;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		p= 1,q= -1;
		for (j= 1;j<=n;j++){
			scanf("%d",&x);
			if (x>q)
				p= j,q= x;
		}
		a[p]++;
	}
	p= 1;
	for (i= 2;i<=n;i++)
		if (a[p]<a[i])
			p= i;
	printf("%d",p);
	return 0;
}
