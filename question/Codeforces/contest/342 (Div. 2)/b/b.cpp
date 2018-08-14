#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e5;
char s[maxn],p[maxn];
int n,m,i,j,ans,bl;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	scanf("%s",p+1);
	n= strlen(s+1);
	m= strlen(p+1);
	for (i= 1;i+m-1<=n;i++){
		bl= 1;
		for (j= 1;j<=m;j++)
			if (s[i+j-1]!=p[j]){
				bl= 0;
				break;
			}
		if (bl){
			ans++;
			i= i+m-1;
		}
	}
	printf("%d",ans);
}
