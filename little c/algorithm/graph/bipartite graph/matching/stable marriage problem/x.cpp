#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn= 1001;
queue<int> q;
int pre[maxn][maxn],order[maxn][maxn],next[maxn];
int futureHusband[maxn],futureWife[maxn];
int n,i,j,x,T;
void engage(int man,int woman){
	int m= futureHusband[woman];
	if (m){
		futureWife[m]= 0;
		q.push(m);
	}
	futureWife[man]= woman;
	futureHusband[woman]= man;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		for (i= 1;i<=n;i++){
			for (j= 1;j<=n;j++)
				scanf("%d",&pre[i][j]);
			futureWife[i]= 0;
			next[i]= 1;
			q.push(i);
		}
		for (i= 1;i<=n;i++){
			for (j= 1;j<=n;j++){
				scanf("%d",&x);
				order[i][x]= j;
			}
			futureHusband[i]= 0;
		}
		while (!q.empty()){
			int man= q.front(),woman= pre[man][next[man]++];
			q.pop();
			if (!futureHusband[woman]) engage(man,woman);
			else if (order[woman][man]<order[woman][futureHusband[woman]])
				engage(man,woman);
			else q.push(man);
		}
		for (i= 1;i<=n;i++)
			printf("%d\n",futureWife[i]);
		if (a1!=T) printf("\n");
	}return 0;	
}
