#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001,base= 1e5,lim= 5;
struct node{
	int a[maxn];
	int k;
	void update(){
		while (a[k+1]>0){
			k++;
			a[k+1]= a[k]/base;
			a[k]%= base;
		}
		while (k>1&&!a[k]) k--;
	}
	void operator *=(const int &x){
		int i;
		for (i= 1;i<=k;i++)	a[i]*= x;
		for (i= 1;i<=k;i++){
			a[i+1]+= a[i]/base;
			a[i]%= base;
		}update();
	}
	void operator /=(const int &x){
		int p= 0,q= 0,i;
		for (i= k;i>=1;i--){
			q= (p*base+a[i])%x;
			a[i]= (p*base+a[i])/x;
			p= q;
		}update();
	}
	void init(){
		memset(a,0,sizeof(a));
		k= 1;
	}
};
node A;
int a[maxn];
int n,i,j,top,sum;
void print(node A){
	int i,j,k= A.k,x,y;
	printf("%d",A.a[k]);
	for (i= k-1;i>0;i--){
		y= 0;x= A.a[i];
		while (x){
			y++;
			x/= 10;
		}if (!y) y++;
		for (j= 1;j<=lim-y;j++)
			printf("0");
		printf("%d",A.a[i]);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==0){
			if (n!=1){
				printf("0");
				return 0;
			}
		}else if (a[i]!=-1){
			if (a[i]<0){
				printf("0");
				return 0;
			}
			top++;
			sum+= a[i]-1;
			if (sum>n-2){
				printf("0");
				return 0;
			}
		}
	}
	if (n==1&&a[1]==0){
		printf("1");
		return 0;
	}
	A.init();A.a[1]= 1;
	for (i= n-2;i>=n-2-sum+1;i--)
		A*= i;	
	for (i= 1;i<=n;i++)
		if (a[i]!=-1)
			for (j= 1;j<=a[i]-1;j++)
				A/= j;
	for (i= 1;i<=n-sum-2;i++)
		A*= n-top;
	print(A);
	return 0;
}
