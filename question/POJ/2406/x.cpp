#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e6;
char s[maxn];
int f[maxn];
int len,i,j,cnt;
void getFail(){
	int i,j= 0;
	f[1]= 0;
	for (i= 2;i<=len;i++){
		while (j&&s[j+1]!=s[i]) j= f[j];
		if (s[j+1]==s[i]) j++;
		f[i]= j;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%s",s+1)>0){
		if (s[1]=='.') break;
		len= strlen(s+1);
		getFail();
		if (len%(len-f[len])==0)
			printf("%d\n",len/(len-f[len]));
		else printf("1\n");
	}return 0;
}
