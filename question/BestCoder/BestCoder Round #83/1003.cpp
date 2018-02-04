#pragma comment(linker, "/STACK:102400000,102400000") 
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 1e5,oo= 1e9+10;
vector<int> g[maxn];
int F[maxn],G[maxn],c[maxn],b[maxn],vis[maxn];
int n,i,j,K,x,y,z,root,bl,T;
void init(){
    int i;
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    for (i= 1;i<=n;i++)
        g[i].clear();
}
void go(int o,int fa,int m){
    if (vis[o]) return;
    vis[o]= 1;
    F[o]= -oo;G[o]= oo;
    int len= g[o].size(),i;
    for (i= 0;i<len;i++){
        int v= g[o][i];
        if (v==fa) continue;
        go(v,o,m);
        F[o]= max(F[o],F[v]-m);
        G[o]= min(G[o],G[v]+m);
    }if (F[o]>G[o]) bl= 0;
}
bool ok(int m){
    memset(vis,0,sizeof(vis));
    int i;
    for (i= 1;i<=n;i++){
        int len= g[i].size();
        if (len==1){
            vis[i]= 1;
            if (b[i]) F[i]= G[i]= c[i];
            else F[i]= -oo,G[i]= oo;
        }
    }
    bl= 1;
    go(root,0,m);
    return bl;
}
int main()
{
#ifndef ONLINE_JUDGE    
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n, &K);
        init();
        for (i= 1;i<n;i++){
            scanf("%d%d",&x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (i= 1;i<=K;i++){
            scanf("%d%d",&x, &y);
            b[x]= 1;
            c[x]= y;
        }
        if (n==2){
            if (K==2) printf("%d\n",abs(c[2]-c[1]));
            else printf("0\n");
        }else {
            for (i= 1;i<=n;i++){
                int len= g[i].size();
                if (len!=1){
                    root= i;
                    break;
                }
            }
            int l= -1,r= oo;
            //int l= -1,r= 10;
            while (l+1<r){
                int m= (l+r)>>1;
                if (ok(m)) r= m;
                else l= m;
            }
            printf("%d\n",r);
        }
    }return 0;
}
