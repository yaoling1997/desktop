#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 4001,maxm= 60000,base= 10000,lim= 4,Max= 50000;
struct high{
	ll a[maxn];
	int k;
};
high A,B;
int a[maxn],b[maxm];
int t,n,d,i,top,sum,x,y;
void get(int x,int o){
	int i,y= sqrt(x)+0.000001;
	for (i= 2;i<=y;i++)
		if (x%i==0){
			while (x%i==0){
				b[i]+= o;
				x/= i;
			}
			if (x==1) break;
		}
	if (x!=1) b[x]+= o;
}
void mul(high &a,int x){
	int i,k= a.k;
	for (i= 1;i<=k;i++) a.a[i]*= x;
	for (i= 1;i<=k;i++)
		a.a[i+1]+= a.a[i]/base,a.a[i]%= base;
	while (a.a[k+1]){
		k++;
		a.a[k+1]= a.a[k]/base;
		a.a[k]%= base;
	}a.k= k;
}
void print(high &a){
	printf("%lld",a.a[a.k]);
	int i,x,y,j;
	for (i= a.k-1;i>0;i--){
		x= a.a[i];
		if (x) y= 0;
		else y= 1;
		while (x){
			x/= 10;
			y++;
		}
		for (j= y+1;j<=lim;j++) printf("0");
		printf("%lld",a.a[i]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&t, &n, &d);
	for (i= 1;i<=t;i++){
		scanf("%d",&a[i]);
		sum+= a[i];
	}
	for (i= 1;i<=n;i++){
		scanf("%d %d",&x, &y);
		get(a[y],1);
		get(sum,-1);sum+= d;a[y]+= d;
	}
	A.a[1]= B.a[1]= 1;A.k= B.k= 1;
	for (i= 2;i<=Max;i++){
		while (b[i]>0){
			b[i]--;
			mul(A,i);
		}
		while (b[i]<0){
			b[i]++;
			mul(B,i);
		}
	}
	print(A);printf("/");print(B);
	return 0;
}
