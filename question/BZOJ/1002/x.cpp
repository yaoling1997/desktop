#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 60,base= 10000,lim= 4;
struct node{
	int a[maxn];
	int k;	
};
node f[3];
int n,i;
void update(node &a){
	int k= a.k,i;
	for (i= 1;i<=k;i++)
		a.a[i+1]+= a.a[i]/base,a.a[i]%= base;
	while (a.a[k+1]){
		k++;
		a.a[k+1]= a.a[k]/base;
		a.a[k]%= base;
	}
	for (i= 1;i<=k;i++)
		if (a.a[i]<0)
			a.a[i]+= base,a.a[i+1]-= 1;
	while (!a.a[k]) k--;
	a.k= k;
}
node operator *(node a,int x){
	int k= a.k,i;
	for (i= 1;i<=k;i++) a.a[i]*= x;
	update(a);
	return a;
}
node operator +(node a,int x){
	a.a[1]+= x;
	update(a);
	return a;
}
node operator -(node a,node b){
	int k= max(a.k,b.k),i;
	for (i= 1;i<=k;i++) a.a[i]-= b.a[i];
	update(a);
	return a;
}
void print(node &a){
	int k= a.k,i,x,p;
	printf("%d",a.a[k]);k--;
	for (i= k;i>0;i--){
		x= a.a[i];p= 0;
		while (x){
			x/= 10;
			p++;
		}if (!p) p= 1;
		while (p<lim){
			p++;
			printf("0");
		}printf("%d",a.a[i]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	f[1]= f[1]+1;f[2]= f[2]+5;
	for (i= 3;i<=n;i++)
		f[i%3]= f[(i-1)%3]*3-f[(i-2)%3]+2;
	print(f[n%3]);
	return 0;
}
