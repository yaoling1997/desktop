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
int h1,h2,day,i,j,a,b;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&h1, &h2);
	scanf("%d%d",&a, &b);
	h1+= 8*a;
	if (h1>=h2) printf("0");
	else {
		if (b>=a){
			printf("-1");
			return 0;
		}
		for (i= 1;i<=3e5;i++){
			h1= h1-12*b+12*a;
			if (h1>=h2){
				printf("%d",i);
				return 0;
			}
		}
		printf("-1");
	}return 0;
}