#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 30001,oo= 1e9;
int a[maxn],f[maxn],sta[maxn];
int n,i,l,r,mid,top,now,m,x;
int getint(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0'||c>'9')&&c!='-') c= getchar();
	if (c=='-') p= -1,c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++) a[i]= getint();
	sta[0]= oo;
	for (i= n;i>0;i--){
		if (a[i]<sta[top]){
			sta[++top]= a[i];
			f[i]= top;
		}
		else {
			l= 0;r= top+1;
			while (l+1<r){
				mid= (l+r)>>1;
				if (sta[mid]>a[i]) l= mid;
				else r= mid;
			}
			sta[l+1]= a[i];
			f[i]= l+1;
		}
	}return 0;
	scanf("%d",&m);
	for (int a1= 1;a1<=m;a1++){
		scanf("%d",&x);
		if (x>top) printf("Impossible");
		else if (x>0){
			now= -oo;
			for (i= 1;i<=n;i++)
				if (now<a[i]&&f[i]>=x){
					x--;
					printf("%d",a[i]);
					if (!x)	break;
					else printf(" ");
					now= a[i];
				}
		}printf("\n");
	}
	return 0;
}
