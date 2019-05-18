#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 1000;
char S[maxn],s[maxn];
int opt,n,i;
char comp(char c,int opt){
	if (opt==0 && 'a'<=c&&c<='z')
		c= c-'a'+'A';
	return c;
}
bool solve(char *p,char *t,int opt){
	int lt= strlen(t+1);
	int lp= strlen(p+1);
	int i,j;
	for (i= 1;i+lp-1<=lt;i++){
		int bl= 1;
		for (j= 1;j<=lp;j++)
			if (comp(t[i+j-1],opt)!=comp(p[j],opt)){
				bl= 0;
				break;
			}		
		if (bl)		
			return 1;
	}
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",S+1);
	scanf("%d",&opt);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		if (solve(S,s,opt))
			printf("%s\n",s+1);
	}
	return 0;
}

