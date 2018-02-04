#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 1e5;
struct gao{
	int a[maxn];
	int k;
	void mt(){
		while (a[k+1]){
			k++;
			a[k+1]= a[k]/10;
			a[k]%= 10;
		}
		while (!a[k]&&k>1) k--;
	}
	void operator *=(const int x){
		int i;
		for (i= 1;i<=k;i++) a[i]*= x;
		for (i= 1;i<=k;i++){
			a[i+1]+= a[i]/10;
			a[i]%= 10;
		}
		mt();
	}
	bool operator <(const gao b){
		if (k<b.k) return 1;
		if (k>b.k) return 0;
		for (int i= k;i>0;i--){
			if (a[i]<b.a[i]) return 1;
			if (a[i]>b.a[i]) return 0;
		}
		return 0;
	}
	void operator -=(const gao b){
		int i;
		for (i= 1;i<=k;i++){
			a[i]-= b.a[i];
			if (a[i]<0){
				a[i]+= 10;
				a[i+1]--;
			}
		}
		mt();
	}
}a,b;
int x,y,i,j,bl;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&x, &y);
	a.a[1]= 1;b.a[1]= 1;
	a.mt();b.mt();
	for (i= 1;i<=y;i++)
		a*= x;
	for (i= 1;i<=x;i++)
		b*= y;
	if (a<b){
		bl= 1;
		swap(a,b);
	}
	a-= b;
	if (bl) printf("-");
	for (i= a.k;i>0;i--)
		printf("%d",a.a[i]);
	return 0;
}
