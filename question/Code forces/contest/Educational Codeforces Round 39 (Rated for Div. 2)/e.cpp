#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
char s[maxn];
int b[100];
int a[maxn],c[maxn],ans[maxn],now[maxn];
int tt,la,n,solved;
void update(int o,int *now){
	int lc=0,tmp=o;
	for (int i=0;i<=9;i++)
		if (b[i]){
			if (tmp>=0){
				tmp--;
				c[++lc]=i;
			}else return;
		}
	while (tmp>=0){
		c[++lc]=9;
		tmp--;
	}
	sort(c+1,c+lc+1);
	while (lc){
		now[lc-1]= c[lc];
		lc--;
	}
	for (int i=0;i<la;i++)
		ans[i]=now[i];
	solved=1;
}
void solve(int o,int *now){
	if (o<0){
		return;
	}
	b[a[o]]^=1;
	now[o]=a[o];
	solve(o-1,now);
	b[a[o]]^=1;
	if (solved)
		return;
	for (int i=a[o]-1;i>=0;i--){
		b[i]^=1;
		now[o]=i;
		update(o-1,now);
		b[i]^=1;
		if (solved)
			return;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d\n",&tt);
	while (tt--){
		scanf("%s",s+1);
		n= strlen(s+1);
		for (int i=1;i<=n;i++)
			a[i-1]=s[n-i+1]-'0';
		bool bl=true;
		if (a[n-1]==1){
			for (int i=0;i<n-1;i++){
				if (i==0&&(a[i]==0||a[i]==1))
					continue;
				if (a[i]!=0)
					bl=false;
			}
		}else bl= false;
		if (bl){
			la=n-2;
			for (int i=0;i<la;i++)
				ans[i]=9;
		}else {
			la=n;
			for (int i=0;i<la;i++)
				ans[i]= now[i]= 0;
			solved=0;
			memset(b,0,sizeof(b));
			solve(la-1,now);
		}
		for (int i=la-1;i>=0;i--)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
