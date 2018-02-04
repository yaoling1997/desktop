#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e3;
struct node{
	int s,p;
};
vector<node> g[maxn];
int a[maxn],b[maxn];
int n,i,j,top,now;
int pos(int x){
	int l= 0,r= top+1;
	while (l+1<r){
		int mid= (l+r)>>1,len= g[mid].size();
		if (g[mid][len-1].s>x) r= mid;
		else l= mid;
	}return r;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++) scanf("%d",&a[i]);
	top= 1;
	g[1].push_back((node){a[1],1});
	for (i= 2;i<=n;i++){
		int p= pos(a[i]);
		if (p>top) top++;
		g[p].push_back((node){a[i],i});
	}
	printf("%d\n",top);
	now= n+1;
	for (i= top;i>0;i--){
		int len= g[i].size();
		for (j= len-1;j>=0;j--)
			if (g[i][j].p<now){
				now= g[i][j].p;
				b[i]= g[i][j].s;
				break;
			}
	}
	for (i= 1;i<=top;i++)
		printf("%d%c",b[i],i<top?' ':'\n');
	return 0;
}
