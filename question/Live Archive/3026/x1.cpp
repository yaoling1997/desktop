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
int len,i,j,cnt,n;
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
	while (scanf("%d",&n)>0){
		if (!n) break;
		cnt++;
		//if (cnt>1) printf("\n");
		printf("Test case #%d\n",cnt);
		scanf("%s",s+1);
		len= strlen(s+1);
		getFail();
		for (i= 2;i<=n;i++)
			if (f[i]&&i%(i-f[i])==0)
				printf("%d %d\n",i, i/(i-f[i]));
		printf("\n");		
	}return 0;
}
