#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 5;
int f[1000],a,b,c,l;
int ans(int o){
	if (f[o]!=-1) return f[o];
	bool d[maxn]= {0};
	if (o-a>=0) d[ans(o-a)]= 1;
	if (o-b>=0) d[ans(o-b)]= 1;
	if (o-c>=0) d[ans(o-c)]= 1;
	int i= 0;
	for (;d[i];) i++;
	f[o]= i;
	return i;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	memset(f,-1,sizeof(f));
	f[0]= 0;
	scanf("%d%d%d%d",&l, &a, &b, &c);
	printf("%d",ans(l)>0);
}
