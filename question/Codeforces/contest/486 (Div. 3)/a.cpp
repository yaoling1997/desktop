#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
set<int> S;
int a[maxn],sta[maxn];
int n,k,la;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d %d",&n, &k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (S.count(a[i]))
			continue;
		sta[++la]=i;
		S.insert(a[i]);
	}
	if (la>=k){
		printf("YES\n");
		for (int i=1;i<=k;i++)
			printf("%d%c",sta[i],i<k?' ':'\n');
	}else
		printf("NO");
	return 0;
}
