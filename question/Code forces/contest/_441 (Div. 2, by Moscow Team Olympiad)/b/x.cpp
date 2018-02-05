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
vector<int> sta[maxn];
int a[maxn];
int n,k,m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &k, &m);
	for (int i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		sta[a[i]%m].pb(a[i]);
	}
	bool bl= 0;
	for (int i= 0;i<m;i++)
		if (sta[i].size()>=k){
			bl= 1;
			printf("Yes\n");
			for (int j= 0;j<k;j++)
				printf("%d%c",sta[i][j],j<k-1?' ':'\n');
			break;
		}
	if (!bl)
		printf("No");
	return 0;
}
