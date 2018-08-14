#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
int x,y,k,n,m,b,p,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d",&n, &b, &p);
	m= n;y= n*p;
	while (m!=1){
		k= log(m)/log(2)+eps;
		k= 1<<k;
		m= k/2+m-k;
		x+= k>>1;
	}
	x= 2*x*b+x;
	printf("%d %d",x, y);
}
