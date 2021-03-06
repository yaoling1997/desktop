#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
const int maxn= 3e5;
char s[maxn],t[maxn],f[maxn][6];
int d[5];
int lt,ls,K,i,j,p,q,bl,ans;
int random(int o){return rand()%o;}
int num(char c){
	if (c=='A') return 1;
	if (c=='T') return 2;
	if (c=='G') return 3;
	if (c=='C') return 4;
	return 0;
}
bool ok(int i){
	int j,k;
	for (j= 1;j<=100;j++)
		if (!f[i+j-1][num(t[j])])
			return 0;
	for (j= lt;j>=lt-100;j--)
		if (!f[i+j-1][num(t[j])])
			return 0;
	for (k= 1;k<=10000;k++){
		j= random(lt-200)+100;
		if (!f[i+j-1][num(t[j])])
			return 0;
	}
	return 1;
}
int main()
{
	srand(time(0));
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
	if ((ll)ls*lt<=2e8){
		for (i= 1;i<=ls;i++){
			bl= 1;
			for (j= 1;j<=lt;j++)
				if (!f[i+j-1][num(t[j])]){
					bl= 0;
					break;
				}
			if (bl) ans++;
		}
	}else {
		for (i= 1;i<=ls;i++)
			if (ok(i)) ans++;		
	}
	printf("%d\n",ans);
	return 0;
}
