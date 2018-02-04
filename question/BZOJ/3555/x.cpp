#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn= 40000,maxl= 300,base= 101;
struct node{
	ull x,y;
	bool operator <(const node &a)const{
		return x<a.x||(x==a.x&&y<a.y);
	}
	bool operator ==(const node &a)const{
		return  x==a.x&&y==a.y;
	}
};
node H[maxn];
ull h[maxn][maxl],d[maxl];
char s[maxn][maxl];
int i,j,l,ans,cnt,n;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &l, &i);
	for (i= 1;i<=n;i++) scanf("%s",s[i]+1);
	d[0]= 1;
	for (i= 1;i<=l;i++) d[i]= d[i-1]*base;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=l;j++)
			h[i][j]= h[i][j-1]*base+s[i][j];
	for (i= 1;i<=l;i++){
		for (j= 1;j<=n;j++){
			H[j].x= h[j][i-1];
			H[j].y= h[j][l]-h[j][i]*d[l-i];
		}
		sort(H+1,H+n+1);
		cnt= 1;
		for (j= 2;j<=n;j++)
			if (H[j]==H[j-1]) cnt++;
			else ans+= cnt*(cnt-1)/2,cnt= 1;
		ans+= cnt*(cnt-1)/2;
	}
	printf("%d",ans);
	return 0;
}
