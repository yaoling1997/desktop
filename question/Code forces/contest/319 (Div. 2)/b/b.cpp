#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e6,maxm= 3e3;
int f[maxm],a[maxn],sta[maxm];
int n,m,i,j,bl,flag,la;
void update(int o){
	la= 0;
	int i,x;
	for (i= m-1;i>=0;i--)
		if (f[i])
			sta[++la]= i;
	for (i= 1;i<=la;i++){
		x= (sta[i]+o)%m;
		if (!f[x])
			f[x]= bl= 1;
	}
	if (!f[o])
		f[o]= bl= 1;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]%= m;
	}
	sort(a+1,a+n+1);
	flag= 1;
	for (i= 1;i<=n;i++){
		if (a[i]!=a[i-1]) flag= 1;
		if (flag){
			bl= 0;
			update(a[i]);
			flag= bl;
		}
	}
	printf("%s",f[0]?"YES":"NO");
}
