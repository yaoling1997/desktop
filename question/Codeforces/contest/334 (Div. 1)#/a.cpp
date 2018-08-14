#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
char s[maxn];
int a[maxn],f[maxn];
int n,i,cnt;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++)
		a[i]= s[i]-'0';
	if (n==1){
		printf("1");
		return 0;
	}
	f[1]= 1;
	for (i= 2;i<=n;i++)
		f[i]= f[i-1]+abs(a[i]-a[i-1]);
	for (i= 2;i<=n;i++)
		if (a[i]==a[i-1])
			cnt++;
	if (cnt>=2) printf("%d",f[n]+2);
	else if (cnt==0) printf("%d",f[n]);
	else {
		printf("%d",f[n]+1);
	}
	return 0;
}
