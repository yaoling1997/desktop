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
char s[maxn];
int n,k,p,len;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	scanf("%s",s+1);
	for (int i=2;i<=n;i++){
		bool bl=1;
		for (int j=1;i+j-1<=n;j++)
			if (s[j]!=s[i+j-1]){
				bl=0;
				break;
			}
		if (bl){
			len=i-1;
			break;
		}
	}
	if (len==0)
		len=n;
	printf("%s",s+1);
	for (int i=2;i<=k;i++)
		for (int j=n-len+1;j<=n;j++)
			printf("%c",s[j]);
	return 0;
}
