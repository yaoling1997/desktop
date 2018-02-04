#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e6;
int ans[maxn];
int i,j,x,y,n,q,a,b;
void update(int &a,int x){
	a+= x;
	if (a>n) a-=n;
	if (a<1) a+= n;
}
void update2(int &a){
	if (a&1) a++;
	else a--;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &q);
	a= 1;b= 2;
	for (i= 1;i<=q;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&x);
			update(a,x);
			update(b,x);
		}else {
			update2(a);
			update2(b);
		}
	}
	for (i= 1;i<=n;i+= 2){
		ans[a]= i;
		a+= 2;
		if (a>n) a-= n;
	}
	for (i= 2;i<=n;i+= 2){
		ans[b]= i;
		b+= 2;
		if (b>n) b-= n;
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}