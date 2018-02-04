#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn= 3001;
int b[maxn];
int i,n,x,ans= 1;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	int ss= (int)(sqrt(n)+0.00000001);
	for (i= 2;i<=ss;i++){
		long long p= i;
		p*= i;
		if (p>n) break;
		while (p<=n){
			b[p]= 1;
			p+= i;
		}
	}
	b[0]= b[1]= 1;
	for (i= 2;i<=n;i++)
		if (!b[i]){
			int p= 1;
			x= n;
			while (x) p+= (x/= i);
			ans*= p;
		}
	printf("%d",ans);
}
