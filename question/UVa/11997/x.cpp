#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn= 1e3;
int d[maxn];
struct node{
	int s,p;
	bool operator <(const node &a)const{
		return s+d[p]>a.s+d[a.p];
	}
};
priority_queue<node> Q;
int a[maxn][maxn];
int i,j,K;
void init(){

}
void merge(int *a,int *b){
	while (!Q.empty()) Q.pop();
	memcpy(d,b,sizeof(d));
	int i;
	for (i= 1;i<=K;i++)
		Q.push((node){a[i],1});
	for (i= 1;i<=K;i++){
		node u= Q.top();
		Q.pop();
		a[i]= u.s+d[u.p];
		if (u.p+1<=K)
			u.p++,Q.push(u);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&K)>0){
		init();
		for (i= 1;i<=K;i++){
			for (j= 1;j<=K;j++)
				scanf("%d",&a[i][j]);
			sort(a[i]+1,a[i]+K+1);
		}
		for (i= 2;i<=K;i++)
			merge(a[1],a[i]);
		for (i= 1;i<=K;i++)
			printf("%d%c",a[1][i],i<K?' ':'\n');
	}return 0;
}
