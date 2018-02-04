#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define gc getchar()
using namespace std;
const int maxn= 100001,maxm= 1e7+1;
int a[maxn],b[maxn],c[maxm],d[maxn],e[maxm];
int n,i,j,l1,l2,r1,r2,ans,bns,Max;
int gi(){
	char c= gc;int re= 0;
	while (c<'0'||c>'9') c= gc;
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc;
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		a[i]= gi();
		c[a[i]]++;Max= max(Max,a[i]);
	}
	for (i= 1;i<=Max;i++) c[i]+= c[i-1];
	for (i= n;i>=1;i--) d[c[a[i]]--]= a[i];
	for (i= 1;i<=n;i++) a[i]= d[i];Max= 0;
	for (i= 1;i<=n;i++){
		b[i]= gi();
		e[b[i]]++;Max= max(Max,b[i]);
	}
	for (i= 1;i<=Max;i++) e[i]+= e[i-1];
	for (i= n;i>=0;i--) d[e[b[i]]--]= b[i];
	for (i= 1;i<=n;i++) b[i]= d[i];
	for (i= 1;i<=2;i++){
		l1= l2= 1;r1= r2= n;ans= bns= 0;
		while (l1<=r1){
			while (l1<=r1&&a[l1]>b[l2])
				ans+= 2,l1++,l2++;
			while (l1<=r1&&a[r1]>b[r2])
				ans+= 2,r1--,r2--;
			if (l1<=r1){
				if (a[l1]==b[r2]) ans++;else bns++;bns++;
				l1++;r2--;
			}
		}
		if (i==1){
			printf("%d ",ans);
			for (j= 1;j<=n;j++)
				swap(a[j],b[j]);
		}else printf("%d",bns);
	}return 0;	
}
