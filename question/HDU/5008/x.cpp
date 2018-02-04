#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const ll maxl= 3e5,maxn= 3e5,M= maxn,MM= 17;
char s[maxn];
ll V[maxl];
int X[maxl],Y[maxl],sa[maxl],c[M+10],height[maxl],f[maxn][20],Min[maxn][20];
ll len,i,l,r,k,v,Q,L,R,K,x,y,ooo;
void build(ll m){
    ll i;
    for (i= 0;i<=m;i++) c[i]= 0;
    for (i= 1;i<=len;i++) c[X[i]]++;
    for (i= 1;i<=m;i++) c[i]+= c[i-1];
    for (i= len;i>0;i--) sa[c[X[i]]--]= i;
    for (ll k= 1;k<=len;k<<= 1){
        ll p= 0;
        for (i= len-k+1;i<=len;i++) Y[++p]= i;
        for (i= 1;i<=len;i++) if (sa[i]>k) Y[++p]= sa[i]-k;
        for (i= 0;i<=m;i++) c[i]= 0;
        for (i= 1;i<=len;i++) c[X[Y[i]]]++;
        for (i= 1;i<=m;i++) c[i]+= c[i-1];
        for (i= len;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
        swap(X,Y);
        X[sa[1]]= p= 1;
        for (i= 2;i<=len;i++)
            if (Y[sa[i-1]]==Y[sa[i]]&&Y[sa[i-1]+k]==Y[sa[i]+k]) X[sa[i]]= p;
            else X[sa[i]]= ++p;
        if (p==len) break;
        m= p;
    }
}
void getHeight(){
    int i,j,k= 0;
    for (i= 1;i<=len;i++){
        if (k) k--;
        j= sa[X[i]-1];
        while (s[i+k]==s[j+k]) k++;
        height[X[i]]= k;//
        continue;
    }
}
void getf(){
    ll i,j;    
    for (i= 1;i<=len;i++){
        f[i][1]= height[i+1];
        f[i][0]= len-sa[i]+1;
        Min[i][0]= sa[i];
        Min[i][1]= min(sa[i],sa[i+1]);
    }
    for (i= 2;i<=MM;i++)
        for (j= 1;j<=len;j++){
            f[j][i]= min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
            f[j][i]= min(f[j][i],height[j+(1<<(i-1))]);
            Min[j][i]= min(Min[j][i-1],Min[j+(1<<(i-1))][i-1]);
        }
}
ll RMQ_f(ll x,ll y){
    if (x>y) swap(x,y);
    ll L= log(y-x+1)/log(2)+eps;
    ll re= min(f[x][L],f[y-(1<<L)+1][L]);
    return re;
}
ll get_left(ll o,ll K){
    ll l= 0,r= o;
    while (l+1<r){
        ll mid= (l+r)>>1;
        if (RMQ_f(mid,o)<K) l= mid;
        else r= mid;
    }return r;
    }
ll get_right(ll o,ll K){
    ll l= o,r= len+1;
    while (l+1<r){
        ll mid= (l+r)>>1;
        if (RMQ_f(o,mid)<K) r= mid;
        else l= mid;
    }return l;
}
void get_ans(ll x,ll y){
    ll L= log(y-x+1)/log(2)+eps;
    ll p= min(Min[x][L],Min[y-(1<<L)+1][L]);
    l= p;r= p+K-1;
}
void init(){    
    l= r= 0;
    memset(f,0,sizeof(f));
    memset(Min,0,sizeof(Min));
    memset(X,0,sizeof(X));
    memset(Y,0,sizeof(Y));
    memset(sa,0,sizeof(sa));
    memset(height,0,sizeof(height));
    memset(V,0,sizeof(V));
	memset(c,0,sizeof(c));
}
int main()
{
    while (scanf("%s",s+1)>0){
		ooo++;
        init();
        len= strlen(s+1);
        for (i= 1;i<=len;i++)
            X[i]= s[i]+1;
        build(M);
        getHeight();
        getf();
        for (i= 1;i<=len;i++)
            V[i]= (ll)len-sa[i]+1-height[i]+V[i-1];
        scanf("%I64d",&Q);
        for (ll q= 1;q<=Q;q++){
            scanf("%I64d",&v);
            k= (l^r^v)+1;
            if (k>V[len]){
                printf("0 0\n");
                l= r= 0;
                continue;
            }
            L= 0;R= len;
            while (L+1<R){
                ll mid= (L+R)>>1;
                if (V[mid]<k) L= mid;
                else R= mid;
            }
            K= k-V[R-1]+height[R];
            x= get_left(R,K);
            y= get_right(R,K);
            get_ans(x,y);
            printf("%I64d %I64d\n",l, r);
        }
    }
    return 0;
}
