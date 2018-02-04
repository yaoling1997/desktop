#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int n,d,h,i,j,x,y,z,now;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &d, &h);
	if (d==1){
		if (n==2) printf("1 2");
		else printf("-1");
	}else {
		now= 2;
		if (d>2*h||d<h){
			printf("-1");
		}else if (d>h){
			for (i= 1;i<=h;i++){
				printf("%d %d\n",now-1, now);
				now++;
			}
			d-= h;
			printf("%d %d\n",1, now);
			now++;
			for (i= 2;i<=d;i++){
				printf("%d %d\n",now-1, now);
				now++;
			}
			while (now<=n){
				printf("%d %d\n",1, now);
				now++;
			}
		}else {
			if (h==1){
				printf("-1");
				return 0;
			}
			for (i= 1;i<=h;i++){
				printf("%d %d\n",now-1, now);
				now++;
			}
			x= now-2;
			while (now<=n){
				printf("%d %d\n",x, now);
				now++;
			}
		}
	}return 0;
}