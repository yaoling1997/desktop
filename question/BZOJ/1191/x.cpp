#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 3001;
bool b[maxn];
int d[maxn],next[maxn],des[maxn],head[maxn];
int n,m,ans,top,i,x,y;
bool find(int o){
	int p= head[o];
	while (p!=0){
		if (!b[des[p]]){
			b[des[p]]= 1;
			if (d[des[p]]==0 || find(d[des[p]])){
				d[des[p]]= o;return 1;
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
	scanf("%d %d\n",&n, &m);
	for (i= 1;i<=m;i++)	{
		scanf("%d %d\n",&x, &y);
		x+= m+1;
		y+= m+1;
		top++;
		des[top]= x;
		next[top]= head[i];
		head[i]= top;
		if (x!=y){
			top++;
			des[top]= y;
			next[top]= head[i];
			head[i]= top;
		}
	}
	for (i= 1;i<=m;i++){
		memset(b,0,sizeof(b));
		if (!find(i)) break;
		ans++;
	}
	printf("%d",ans);
	return 0;	
}
