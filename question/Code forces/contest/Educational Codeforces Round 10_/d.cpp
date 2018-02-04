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
const int maxn= 1e6;
struct line{
	int x,y,h;
	bool operator <(const line a)const{
		return x<a.x||(x==a.x&&y>a.y);
	}
};
map<int,int> M;
line a[maxn];
int ans[maxn],sta[maxn],c[maxn];
int i,n,m,la;
void change(int o,int v){
	while (o<=m){
		c[o]+= v;
		o+= o&-o;
	}
}
int find(int o){
	int re= 0;
	while (o){
		re+= c[o];
		o-= o&-o;
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&a[i].x, &a[i].y);
		sta[++la]= a[i].x;
		sta[++la]= a[i].y;
		a[i].h= i;
	}
	sort(sta+1,sta+la+1);
	M[sta[1]]= ++m;
	for (i= 2;i<=la;i++){
		if (sta[i]==sta[i-1]) continue;
		M[sta[i]]= ++m;
	}
	for (i= 1;i<=n;i++){
		a[i].x= M[a[i].x];
		a[i].y= M[a[i].y];
		change(a[i].y,1);
	}
	sort(a+1,a+n+1);
	for (i= 1;i<=n;i++){
		change(a[i].y,-1);
		ans[a[i].h]= find(a[i].y);
	}
	for (i= 1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}