#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 100;
ll d[maxn],a[maxn];
ll odd,even,n,i,j,x,y,L,T,ans;
ll C(ll m,ll n){
    ll re= 1,i;
    for (i= 1;i<=n;i++)
        re= re*(m-i+1)/i;
    return re;
}
int main()
{
#ifndef ONLINE_JUDGE    
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    scanf("%I64d",&T);
    while (T--){
        scanf("%I64d",&n);
        for (i= 1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        odd= even= 0;
        for (i= 1;i<=n;i++){
            L= n-i;
            x= y= 0;
            for (j= 0;j<=L;j+= 2)
                x+= C(L,j);
            x*= a[i];
            for (j= 1;j<=L;j+= 2)
                y+= C(L,j);
            y*= a[i];
            odd+= x;
            even+= y;
        }
        ans= odd-even;
        printf("%I64d\n",abs(ans));
    }return 0;
}
