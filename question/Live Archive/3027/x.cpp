#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e4;
char s[5];
int f[maxn],d[maxn];
int n,i,x,y,T;
int find(int o){
	if (o==f[o]) return o;
	int r= find(f[o]);
	d[o]+= d[f[o]];
	return f[o]= r;
}
void init(){
	int i;
	for (i= 1;i<=n;i++){
		f[i]= i;
		d[i]= 0;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		init();
		for (;;){
			scanf("%s",s+1);
			if (s[1]=='O') break;
			if (s[1]=='E'){
				scanf("%d",&x);
				find(x);
				printf("%d\n",d[x]);
			}else {
				scanf("%d%d",&x, &y);
				f[x]= y;
				d[x]= abs(x-y)%1000;
			}
		}
	}return 0;
}
