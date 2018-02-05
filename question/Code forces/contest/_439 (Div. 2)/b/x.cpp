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
ll a,b;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d",&a, &b);
	if (b-a>=10)
        printf("0");
    else {
        ll sum=1;
        for (ll i= a+1;i<=b;i++)
            sum=sum*i%10;
        printf("%I64d",sum);
    }
    return 0;
}
