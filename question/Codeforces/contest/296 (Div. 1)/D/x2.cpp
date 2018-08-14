#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5;
char s[maxn],t[maxn];
int F[maxn][6],l[maxn];
int lt,ls,K,i,j,k,p,q,bl,ans,f,r;
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
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&ls, &lt, &K);
	scanf("%s%s",s+1, t+1);
	p= 1;q= min(1+K,ls);
	for (i= 1;i<=min(1+K,ls);i++)
		F[1][num(s[i])]++;
	for (i= 2;i<=ls;i++){
		memcpy(F[i],F[i-1],sizeof(F[i]));
		if (q+1<=ls){
			q++;
			F[i][num(s[q])]++;
		}
		if (i-p>K){
			F[i][num(s[p])]--;
			p++;
		}
	}
	for (i= 1;i<=ls;i++){
		bl= 1;
		for (j= 1;j<=4;j++)
			if (F[i][j]==0){
				bl= 0;
				break;
			}
		if (bl==0) l[++r]= i;
	}
	f= 1;
	for (i= 1;i<=ls-lt+1;i++){
		while (f<=r && l[f]<i)
			f++;
		bl= 1;
		for (k= f;k<=r;k++){
			if (l[k]-i+1>lt) break;
			j= l[k]-i+1;
			if (!F[i+j-1][num(t[j])]){
				bl= 0;
				break;
			}
		}
		if (bl)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}