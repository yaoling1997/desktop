#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
char s[maxn];
int a[maxn];
int n,i,tot,ans;
template<class T>
int sum(T *a,int n){
	int re= 0,i;
	for (i= 1;i<=n;i++)
		re+= a[i];
	return re;
}
template<class T>
int get(T *a,int n){
	int re= 0,i;
	for (i= 1;i<=n;i++)
		re+= a[i];
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (i= 1;i<=n;i++)	s[i]= 48;
	for (i= 1;i<=n;i++) a[i]= 48;
	ans= sum(s,n);
	printf("%d\n",ans);
	ans= sum(a,n);
	printf("%d\n",ans);
	return 0;
}
