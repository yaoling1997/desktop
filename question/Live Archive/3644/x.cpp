#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e5;
int f[maxn];
int x,y,ans;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void init(){
	for (int i= 1;i<=1e5;i++) f[i]= i;
	ans= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	init();
	while (scanf("%d",&x)>0){
		if (x==-1){
			printf("%d\n",ans);
			init();
			continue;
		}
		scanf("%d",&y);
		find(x);find(y);
		if (f[x]==f[y]) ans++;
		else f[f[x]]= f[y];
	}return 0;
}
