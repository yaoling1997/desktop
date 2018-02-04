#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5;
char s[maxn],t[maxn],f[maxn][6];
int d[5];
int lt,ls,K,i,j,p,q,bl,ans;
int num(char c){
	if (c=='A') return 1;
	if (c=='T') return 2;
	if (c=='G') return 3;
	if (c=='C') return 4;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d%d",&ls, &lt, &K);
	scanf("%s%s",s+1, t+1);
	p= 1;q= min(1+K,ls);
	for (i= 1;i<=min(1+K,ls);i++)
		f[1][num(s[i])]++;
	for (i= 2;i<=ls;i++){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		if (q+1<=ls){
			q++;
			f[i][num(s[q])]++;
		}
		if (i-p>K){
			f[i][num(s[p])]--;
			p++;
		}
	}
	for (i= 1;i<=ls;i++){
		bl= 1;
		for (j= 1;j<=lt;j++)
			if (!f[i+j-1][num(t[j])]){
				bl= 0;
				break;
			}
		if (bl) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
