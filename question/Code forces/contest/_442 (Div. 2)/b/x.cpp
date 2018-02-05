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
int aSum[maxn],bSum[maxn];
char s[maxn];
int ans,sum;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	int len= strlen(s+1);
	for (int i= 1;i<=len;i++){
		aSum[i]= aSum[i-1]+(s[i]=='a');
		bSum[i]= bSum[i-1]+(s[i]=='b');
		sum+= s[i]=='a';
	}
	ans= sum;
	for (int i= 1;i<=len;i++)
		for (int j= i;j<=len;j++)
			ans= max(ans,
							 bSum[j]-bSum[i-1]+aSum[i-1]+aSum[len]-aSum[j]);
	printf("%d",ans);
	return 0;
}
