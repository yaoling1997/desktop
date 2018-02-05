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
int X[maxn];
int n,m,i;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	m= 1;
    X[0]= 1;
	for (i= 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if (X[x]!=0){
            X[x]--;
            X[i]++;
        }else {
            m++;
            X[i]++;
        }
	}
	printf("%d",m);
	return 0;
}
