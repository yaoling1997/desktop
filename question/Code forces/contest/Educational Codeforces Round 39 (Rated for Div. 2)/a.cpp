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
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	int B= 0,C= 0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x>0)
			B+=x;
		else C+= x;
	}
	printf("%d",B-C);
	return 0;
}
