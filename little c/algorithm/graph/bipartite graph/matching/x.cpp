#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
int d[maxn],des[maxn],head[maxn],next[maxn],b[maxn];
int x,y,n1,n,m,i,top,ans,time;
bool find(int o){
	int p= head[o];
	while (!p){
		if (b[des[p]]!=time){
			b[des[p]]= time;
			if (!d[des[p]] || find(d[des[p]])){
				d[des[p]]= o;
				return 1;
			}
		}
		p= next[p];
	}
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n1, &n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		top++;
		des[top]= y;
		next[top]= head[x];
		head[x]= top;
		top++;
		des[top]= x;
		next[top]= head[y];
		head[y]= top;
	}
	for (i= 1;i<=n1;i++){
		time++;
		if (find(i)) ans++;
	}
	printf("%d",ans);
	return 0;
}
