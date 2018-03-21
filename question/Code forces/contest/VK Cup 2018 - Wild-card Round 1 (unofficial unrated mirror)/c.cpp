#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define maxn 500000
int a[maxn];
int n,now,len,bl;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[1];
	a[n+1]=!a[n];
	n++;
	bl=1;
	for (int i=1;i<=n;i++)
		if (a[i]==a[i-1]){
			now++;
		}else {
			if (!len)
				len=now;
			if (len!=now){
				bl=0;
				break;
			}
			now=1;
		}
	printf("%s",bl?"YES":"NO");
	return 0;
}
