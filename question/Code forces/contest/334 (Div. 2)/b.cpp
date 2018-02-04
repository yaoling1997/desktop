#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5;
int s[maxn];
int n,k,i,l,r,re;
bool ok(int m){
	int i,p,q;
	p= 1;
	q= n;
	for (i= 1;i<=re;i++){
		if (s[q]<=m) q--;
		else return 0;
		if (q<=0) return 1;
	}
	for (i= 1;i<=k-re;i++)
		if (s[p]+s[q]<=m) p++,q--;
		else return 0;
	return 1;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	re= (k-n/2)*2-n%2;
	for (i= 1;i<=n;i++)
		scanf("%d",&s[i]);
	l= 0,r= 3e6;
	while (l+1<r){
		int m= (l+r)>>1;
		if (ok(m)) r= m;
		else l= m;
	}
	printf("%d\n",r);
	return 0;
}
