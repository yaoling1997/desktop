#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
int a[maxn];
int n,m,i,x;
void up(int o){
	while (o/2&&a[o/2]<a[o])
		swap(a[o/2],a[o]),o/= 2;
}
void down(int o){
	int t= o;
	if (2*o<=n&&a[2*o]>a[t]) t= 2*o;
	if (2*o+1<=n&&a[2*o+1]>a[t]) t= 2*o+1;
	if (o!=t){
		swap(a[t],a[o]);
		down(t);
	}
}
void build(){
	for (int i= n/2;i>0;i--)
		down(i);
}
void insert(int x){
	a[++n]= x;
	up(n);
}
void pop(){
	if (!n) return;
	a[1]= a[n--];
	down(1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	build();
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		insert(x);
	}
	while (n){
		printf("%d%c",a[1],n-1?' ':'\n');
		pop();
	}
	return 0;
}
