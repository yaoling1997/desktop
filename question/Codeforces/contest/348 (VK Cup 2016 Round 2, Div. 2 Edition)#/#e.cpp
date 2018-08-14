#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
map<int,int> a[maxn],h;
int tot,n,i,j,q,t,x,Max= 1e9,ans,y;
void change(int v,int o,int x){
	while (o<=Max){
		a[v][o]+= x;
		o+= o&-o;
	}
}
int find(int v,int o){
	int re= 0;
	while (o){
		re+= a[v][o];
		o-= o&-o;
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d%d",&q, &t, &x);
		if (q==1){
			if (!h.count(x))
				h[x]= ++tot;
			//y= h[x];
			change(h[x],t,1);
		}else if (q==2){
			y= h[x];
			change(h[x],t,-1);			
		}else {
			ans= find(h[x],t);
			printf("%d\n",ans);
		}
	}return 0;
}
