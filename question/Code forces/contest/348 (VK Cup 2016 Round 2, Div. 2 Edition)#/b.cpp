#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn];
int vis[maxn],d[maxn];
int i,n,ans,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++)
		scanf("%d",&d[i]);
	now= 1;
	for (;;){
		vis[now]= 1;
		if (s[now]=='>'){
			now+= d[now];
		}else {
			now-= d[now];
		}
		if (now>n||now<1){
			printf("FINITE\n");
			return 0;
		}
		if (vis[now]){
			printf("INFINITE\n");
			return 0;			
		}
	}
	return 0;
}