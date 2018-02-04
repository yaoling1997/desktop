#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e5;
ll c[maxn],a[20],P[20],M[20];
ll p,n,m,ans,i,j,T,k;
void gcd(ll a,ll b,ll &x,ll &y){
    if (!b){
        x= 1;y= 0;
        return;
    }
    gcd(b,a%b,x,y);
    ll t= x;
    x= y;
    y= t-a/b*y;
}
ll lucas(ll m,ll n,ll p){
    ll re= 1,x,y;
    while (n||m){
        if (n%p>m%p) return 0;
        re= re*c[m%p]%p;
        gcd(c[m%p-n%p]*c[n%p]%p,p,x,y);
        re= re*x%p;
        n/= p;m/= p;
    }return (re+p)%p;
}
ll mul(ll a,ll b,ll mo){
    if (a<0) a+= mo;
    if (b<0) b+= mo;
    ll re= 0;
    while (b){
        if (b&1) re= (re+a)%mo;
        a= (a+a)%mo;b>>= 1;
    }return re;
}
ll china(ll *a,ll *m,ll n){
    ll M= 1,i,x= 0,p,q;
    for (i= 1;i<=n;i++) M*= m[i];
    for (i= 1;i<=n;i++){
        ll w= M/m[i];
        gcd(w,m[i],p,q);
        x= (x+mul(mul(w,p,M),a[i],M))%M;
    }return (x+M)%M;
}
void init(){}
int main()
{
    scanf("%I64d",&T);
    for (ll TT= 1;TT<=T;TT++){
        init();
        scanf("%I64d%I64d%I64d",&n, &m, &k);
        for (i= 1;i<=k;i++){
            scanf("%I64d",&P[i]);
            M[i]= P[i];
            p= P[i];
            c[0]= 1;
            for (j= 1;j<=p;j++)
                c[j]= c[j-1]*j%p;
            a[i]= lucas(n,m,p);
        }
        ans= china(a,M,k);
        printf("%I64d\n",ans);
    }
    return 0;
}
