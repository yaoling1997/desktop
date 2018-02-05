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
int n,t;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &t);
	for (int i= 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		x= 86400-x;
		t-= x;
		if (t<=0){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
