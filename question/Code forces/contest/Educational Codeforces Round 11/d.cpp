#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e6;
pair<int,int> P[maxn],L[maxn];
ll ans,k;
int n,i,j,m,x,y;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		P[i]= make_pair(x,y);
	}
	for (i= 1;i<=n;i++)
		for (j= i+1;j<=n;j++){
			pair<int,int> u= P[i];
			pair<int,int> v= P[j];
			if (u>v) swap(u,v);
			L[++m]= make_pair(v.first-u.first,v.second-u.second);
		}
	sort(L+1,L+m+1);
	for (i= 1;i<=m;i= j){
		j= i+1;
		while (j<=m&&L[i]==L[j]) j++;
		k= j-i;
		ans+= k*(k-1)/2;
	}
	ans/= 2;
	printf("%I64d",ans);
	return 0;
}
