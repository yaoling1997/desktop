#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
queue<int> Q;
int a[maxn];
ll k;
int n,K,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%I64d",&n, &k);
	K= min(k,(ll)n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		Q.push(i);
	}
	int u= Q.front(),cnt= 0;
	Q.pop();
	for(;;){
		int x= Q.front();
		Q.pop();
		if (a[u]>a[x]){
			cnt++;
			Q.push(x);
		}else {
			cnt= 1;
			Q.push(u);
			u= x;
		}
		if (cnt>=K)
			break;
	}
	printf("%d",a[u]);
	return 0;
}
