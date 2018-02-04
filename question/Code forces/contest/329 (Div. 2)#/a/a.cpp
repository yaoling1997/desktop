#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3e3;
char s[maxn];
int f[300][300];
bool b[300];
int sta[300];
int i,j,n,cnt,la,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (int N= 1;N<=n;N++){
		memset(b,0,sizeof(b));
		scanf("%s",s+1);
		int len= strlen(s+1);
		la= 0;
		for (i= 1;i<=len;i++)
			if (!b[s[i]]){
				sta[++la]= s[i];
				b[s[i]]= 1;				
			}
		if (la==1){
			for (i= 'a';i<='z';i++){
				f[sta[1]][i]+= len;
				f[i][sta[1]]+= len;
			}
			f[sta[1]][sta[1]]-= len;
		}else if (la==2){
			f[sta[1]][sta[2]]+= len;
			f[sta[2]][sta[1]]+= len;
		}
	}
	for (i= 'a';i<='z';i++)
		for (j= 'a';j<='z';j++)
			ans= max(ans,f[i][j]);
	printf("%d\n",ans);
	return 0;
}
