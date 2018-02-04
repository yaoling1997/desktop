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
int t[maxn];
int sta[maxn];
int la,n,k,q,i,x,y,z;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &k, &q);
	for (i= 1;i<=n;i++)
		scanf("%d",&t[i]);
	for (int qq= 1;qq<=q;qq++){
		scanf("%d%d",&x, &y);
		if (x==1){
			if (la<k) sta[++la]= y;
			else {
				z= 1;
				for (i= 2;i<=la;i++)
					if (t[sta[i]]<t[sta[z]])
						z= i;
				if (t[sta[z]]<t[y])
					sta[z]= y;
			}
		}else {
			int bl= 0;
			for (i= 1;i<=la;i++)
				if (sta[i]==y)
					bl= 1;
			if (bl) printf("YES\n");
			else printf("NO\n");
		}
	}return 0;
}