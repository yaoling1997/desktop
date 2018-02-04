#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 10001;
int next[2*maxn],des[2*maxn],head[maxn],d[maxn],X[maxn];
int vis[maxn];
int n,x,i,x1,x2,tot,time;
void add(int o,int x){
	tot++;
	next[tot]= head[o];
	des[tot]= x;
	head[o]= tot;	
}
bool find(int o){
	for (int p= head[o];p;p= next[p]){
		int v= des[p];
		if (vis[v]!=time){
			vis[v]= time;
			if (d[v]==-1||find(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 0;i<n;i++){
		d[i]= -1;
		scanf("%d",&x);
		x1= i-x;x2= i+x;
		if (x1<0) x1+= n;
		if (x2>=n) x2-= n;
		if (x1>x2) swap(x1,x2);
		add(i,x2);add(i,x1);
	}
	for (i= n-1;i>=0;i--){
		time++;
		if (!find(i)){
			printf("No Answer");
			return 0;
		}
	}
	for (i= 0;i<n;i++)
		X[d[i]]= i;
	for (i= 0;i<n;i++)
		printf("%d%c",X[i],i<n-1?' ':'\n');
	return 0;
}
