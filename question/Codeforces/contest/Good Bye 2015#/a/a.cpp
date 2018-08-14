#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5;
char s[maxn],t[maxn];
int x,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%s%s",&x, s+1,t+1);
	if (t[1]=='w'){
		if (5<=x&&x<=6) ans= 53;
		else ans= 52;
	}else {
		if (x<=29) ans= 12;
		else if (x<=30) ans= 11;
		else ans= 7;
	}
	printf("%d\n",ans);
	return 0;
}
