#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn],st[maxn];
int n,i,j,cnt,x,y= 1,bl,len;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	st[1]= '1';
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		len= strlen(s+1);
		if (len==1&&s[1]=='0'){
			printf("0");
			return 0;
		}
		bl= 1;
		if (s[1]!='1') bl= 0;
		for (j= 2;j<=len;j++)
			if (s[j]!='0') bl= 0;
		if (bl) cnt+= len-1;
		else {
			memcpy(st,s,sizeof(s));
		}
	}
	printf("%s",st+1);
	for (i= 1;i<=cnt;i++)
		printf("0");
	return 0;
}
