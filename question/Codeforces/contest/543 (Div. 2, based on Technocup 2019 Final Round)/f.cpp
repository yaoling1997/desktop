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
const int maxn= 5e3+10;
char s[maxn];
int f[maxn],g[maxn];
int n,a,b;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &a, &b);
	scanf("%s",s+1);
	f[1]=a;
	for (int i=2;i<=n;i++){
		f[i]=f[i-1]+a;
		for (int j=i-1;j>0;j--){
			if (s[j]==s[i]){
				g[j]=g[j-1]+1;
				f[i]=min(f[i],f[max(i-g[j],j)]+b);
			}else
				g[j]=0;
		}
	}
	printf("%d",f[n]);
	return 0;
}
