#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3;
char s[maxn];
int n,i,j,k,x,y,ans;
void move(char c,int &x,int &y){
	if (c=='U') x--;
	if (c=='R') y++;
	if (c=='D') x++;
	if (c=='L') y--;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++)
		for (j= i;j<=n;j++){
			x= y= 0;
			for (k= i;k<=j;k++)
				move(s[k],x,y);
			if (!x&&!y) ans++;
		}
	printf("%d\n",ans);
	return 0;
}
