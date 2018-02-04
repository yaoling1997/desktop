#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps= 1e-8,PI= acos(-1);
const int maxn= 30001;
double area[maxn];
double l,r;
int n,F,cnt,i,T;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d",&n, &F);F++;r= 0;
		for (i= 1;i<=n;i++){
			scanf("%lf",&area[i]);
			area[i]*= area[i]*PI;
			r= max(r,area[i]);
		}
		l= 0;
		while (r-l>1e-5){
			double mid= (l+r)/2;cnt= 0;
			for (i= 1;i<=n;i++)
				cnt+= floor(area[i]/mid);
			if (cnt>=F) l= mid;
			else r= mid;
		}printf("%.4lf\n",l);		
	}return 0;
}
