#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 1e6;
vector<int> v[maxn];
int X[maxn],Y[maxn],b[maxn];
ll ans;
int n,m,i,j,x,y,p,q;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&X[i]);
		Y[X[i]]= i;
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		p= Y[x];
		q= Y[y];
		if (p>q) swap(p,q);
		b[q]++;
		v[p].push_back(q);
	}
	j= 1;
	for (i= 1;i<=n;i++){
		while (j<=n&&!b[j]) j++;
		ans+= j-i;
		int len= v[i].size(),k;
		for (k= 0;k<len;k++){
			x= v[i][k];
			b[x]--;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}