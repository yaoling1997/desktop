#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn];
int n,p,q,i,j,k,z,ap,aq,bl,cnt;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &p, &q);
	scanf("%s",s+1);
	for (i= 0;i<=100;i++)
		for (j= 0;j<=100;j++){
			k= i*p+j*q;
			if (k>n) break;
			if (k==n){
				bl= 1;
				goto pn;
			}
		}
 pn:if (bl){
		printf("%d\n",i+j);
		for (k= 1;k<=i;k++){
			for (z= 1;z<=p;z++){
				cnt++;
				printf("%c",s[cnt]);
			}
			printf("\n");
		}
		for (k= 1;k<=j;k++){
			for (z= 1;z<=q;z++){
				cnt++;
				printf("%c",s[cnt]);
			}
			printf("\n");
		}
	}else printf("-1");
	return 0;
}
