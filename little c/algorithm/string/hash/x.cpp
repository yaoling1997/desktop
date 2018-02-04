#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn =300000,base= 31,mo= 1000000007;
char s[maxn];
ll d[maxn],h[maxn];
int i,j,x,y,m,len;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	d[0]= 1;
	for (i= 1;i<=len;i++){
		d[i]= d[i-1]*base%mo;
		h[i]= (h[i-1]*base+s[i]-'A')%mo;
	}
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x, &y);
		int l= 0,r= min(len-x+1,len-y+1)+1;
		while (l+1<r){
			int mid= (l+r)>>1;
			ll g1= (h[x+mid-1]-h[x-1]*d[mid])%mo;
			ll g2= (h[y+mid-1]-h[y-1]*d[mid])%mo;
			if (g1<0) g1+= mo;
			if (g2<0) g2+= mo;
			if (g1==g2) l= mid;
			else r= mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
