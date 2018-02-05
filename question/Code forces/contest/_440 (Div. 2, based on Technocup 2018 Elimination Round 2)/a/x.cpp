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
int vis[20];
int a[20],b[20];
int x,n,m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i= 0;i<n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	for (int i= 0;i<m;i++){
		scanf("%d",&b[i]);
		vis[b[i]]++;
	}
	for (int i= 1;i<=9;i++)
		if (vis[i]==2){
			x= i;
			break;
		}
	if (!x){
		sort(a,a+n);
		sort(b,b+m);
		x= min(a[0],b[0])*10+max(a[0],b[0]);
	}
	printf("%d",x);
	return 0;
}
