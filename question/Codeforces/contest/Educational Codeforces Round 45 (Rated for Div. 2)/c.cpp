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
int a[maxn],b[maxn],c[maxn];
char s[maxn];
ll ans;
int n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int sum=0;
		for (int j=1;j<=len;j++)
			if (s[j]==')'){
				if (sum==0){
					a[i]++;
				}else sum--;
			}else {
				sum++;
			}
		b[i]=sum;
		if (b[i]==0)
			c[a[i]]++;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==0)
			ans+=c[b[i]];
	printf("%I64d",ans);
	return 0;
}
