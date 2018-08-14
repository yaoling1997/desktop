#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int i,n,x,y,z,cnt;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%d",&y);
	for (int i=2;i<=n;i++){
		scanf("%d",&z);
		if (x!=0){
			if ((x<y&&y>z)||(x>y&&y<z))
				cnt++;
		}
		x=y;
		y=z;
	}
	printf("%d",cnt);
	return 0;
}
