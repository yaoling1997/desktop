#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const int maxn= 2e3;
map<int,int> M;
int a[maxn],sta[maxn];
int ans,n,i,j,x,y,t,la;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		if (!M.count(a[i])) M[a[i]]= 1;
		else M[a[i]]++;
		if (a[i]==0) x++;
	}
	ans= max(2,x);
	for (i= 1;i<=n;i++){
		M[a[i]]--;
		for (j= 1;j<=n;j++){
			if (i==j) continue;
			if (a[i]==0&&a[j]==0) continue;
			M[a[j]]--;
			y= a[j];
			x= a[i]+a[j];
			while (M.count(x)&&M[x]){
				M[x]--;
				sta[++la]= x;
				t= x+y;
				y= x;
				x= t;
			}
			ans= max(ans,la+2);
			while (la){
				M[sta[la]]++;
				la--;
			}
			M[a[j]]++;
		}
		M[a[i]]++;
	}
	printf("%d",ans);
	return 0;
}
