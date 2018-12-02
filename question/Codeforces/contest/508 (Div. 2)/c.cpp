#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int a[2][maxn];
ll A[2];
int n;
void solve(int o,int la,int lb){
	if (!la&&!lb)
		return;
	int p[2]={la,lb};
	if (!p[o]||(p[o^1]&&a[o][p[o]]<a[o^1][p[o^1]]))
		p[o^1]--;
	else{
		A[o]+=a[o][p[o]];
		p[o]--;
	}
	solve(o^1,p[0],p[1]);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[0][i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[1][i]);
	for (int i=0;i<2;i++)
	sort(a[i]+1,a[i]+n+1);
	solve(0,n,n);
	printf("%I64d",A[0]-A[1]);
	return 0;
}
