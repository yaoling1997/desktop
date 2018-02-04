#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3e5;
char s[maxn],st[maxn];
int c[maxn],X[maxn],sa[maxn],Y[maxn];
int n,m,len,i,T,L,a,b;
void build(int m){
    int i;
    for (i= 0;i<=m;i++) c[i]= 0;
    for (i= 1;i<=len;i++) c[X[i]]++;
    for (i= 1;i<=m;i++) c[i]+= c[i-1];
    for (i= len;i>0;i--) sa[c[X[i]]--]= i;
    for (int k= 1;k<=len;k<<= 1){
        int p= 0;
        for (i= len-k+1;i<=len;i++) Y[++p]= i;
        for (i= 1;i<=len;i++)
            if (sa[i]>k)
                Y[++p]= sa[i]-k;
        for (i= 0;i<=m;i++) c[i]= 0;        
        for (i= 1;i<=len;i++) c[X[Y[i]]]++;
        for (i= 1;i<=m;i++) c[i]+= c[i-1];
        for (i= len;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
        swap(X,Y);
        p= 1;X[sa[1]]= 1;
        for (i= 2;i<=len;i++)
            if (Y[sa[i-1]]==Y[sa[i]] && Y[sa[i-1]+k]==Y[sa[i]+k])
                X[sa[i]]= p;
            else X[sa[i]]= ++p;
        if (p==len) break;
        m= p;
    }
}
char C(int x){
    while (x>L) x-= L;
    while (x<=0) x+= L;
    return s[x];
}
void choose(int a,int b){
    int i,bl= 0;
    for (i= 1;i<=L;i++){
        if (C(a+i-1)>C(b-i+1)) bl= 1;
        if (C(a+i-1)<C(b-i+1)) bl= 2;
        if (bl) break;
    }
    if (bl==0&&a>b)
        bl= 2;    
    if (bl!=2) printf("%d %d\n",a, 0);
    else printf("%d %d\n",b, 1);
}
void init(){
    memset(X,0,sizeof(X));
    memset(Y,0,sizeof(Y));
    memset(sa,0,sizeof(sa));    
    memset(c,0,sizeof(c));    
}
int main()
{
    scanf("%d",&T);
    for (int TT= 1;TT<=T;TT++){
        init();
        scanf("%d",&L);
        scanf("%s",s+1);
        len= 2*L;
        for (i= 1;i<=L;i++)
            st[i]= s[i],st[i+L]= s[i];
        for (i= 1;i<=len;i++)
            X[i]= st[i]-'a'+1;
        build(28);
        a= sa[len];
        init();
        for (i= 1;i<=L;i++)
            swap(st[i],st[len-i+1]);
        st[++len]= 'z'+1;
        for (i= 1;i<=len;i++)
            X[i]= st[i]-'a'+1;
        build(28);
        for (i= len;i>0;i--)
            if (sa[i]<=L){
                b= sa[i];
                break;
            }
        b= L-b+1;
        choose(a,b);        
    }return 0;
}

