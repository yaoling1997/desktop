#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll oo= 1e18;
const int maxl= 50,maxn= 200000;
char s[maxn][maxl];
ld f[maxn],g[maxn];
int sum[maxn],q1[maxn],q2[maxn],stack[maxn];
ld x,y;
int i,j,n,l,P,bot,top,T,ooo,sh;
ld count(ld x){
	x= fabs(x);
	ld re= 1;
	for (int i= 1;i<=P;i++){
		re*= x;
		//if (re>oo) return oo+1;
	}return re;
}
ld get(int i,int j){
	return f[j]+count(sum[i]-sum[j]+i-j-1-l);	
}
void update(int o){
	if (q2[bot]<=o) bot++;
	q1[bot]= o+1;
	int i,j;
	while (bot<=top){
		j= stack[top];i= q1[top];
		if (get(i,j)>=get(i,o)) top--;
		else {
			int l= q1[top],r= q2[top]+1;
			while (l+1<r){
				i= (l+r)>>1;
				x= get(i,j);y= get(i,o);
				//if (x>oo||x>=y) r=i;
				if (x>=y) r=i;				
				else l= i;
			}
			q2[top]= l;
			break;
		}
	}
	if (q2[top]!=n)
		stack[++top]= o,q1[top]= q2[top-1]+1,q2[top]= n;
}
void print(int n){
	if (n==0) return;
	print(g[n]);
	for (int i= g[n]+1;i<=n;i++)
		printf("%s%c",s[i]+1,i<n?' ':'\n');
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d %d",&n, &l, &P);
		for (i= 1;i<=n;i++){
			scanf("%s",s[i]+1);
			sum[i]= strlen(s[i]+1);
			sum[i]+= sum[i-1];
		}stack[bot= top= 1]= 0;q1[top]= 1;q2[top]= n;
		for (i= 1;i<=n;i++){
			if (i==sh)
				ooo++;
			j= stack[bot];
			f[i]= get(i,j);
			g[i]= j;
			if (i!=n) update(i);
		}
		if (f[n]<=oo){
			printf("%.0Lf\n",f[n]);
			//print(n);
		}
		else printf("Too hard to arrange\n");
		printf("--------------------\n");
	}return 0;
}
