#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<functional>  
#include<cmath>  
using namespace std; 
#define MAXN (50000+10)  
#define INF (1000000000)  
#define eps 1e-6  
struct P 
{ 
    double x,y; 
    P(){} 
    P(double _x,double _y):x(_x),y(_y){} 
    friend bool operator<(P a,P b){return (fabs(a.y-b.y)<eps)?a.x<b.x:a.y<b.y;  } 
    friend bool operator==(P a,P b){return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;} 
    friend bool operator!=(P a,P b){return !(a==b);} 
     
}a[MAXN],s[MAXN],ansp[5]; 
int size=0; 
double ans=INF; 
double dis2(P a,P b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);} 
struct V 
{ 
    double x,y; 
    V(){} 
    V(double _x,double _y):x(_x),y(_y){} 
    V(P a,P b):x(b.x-a.x),y(b.y-a.y){} 
    friend double operator*(V a,V b){return a.x*b.y-a.y*b.x;} 
    friend V operator*(double a,V b){return V(a*b.x,a*b.y);} 
    friend double operator/(V a,V b){return a.x*b.x+a.y*b.y;} 
    friend P operator+(P a,V b){return P(a.x+b.x,a.y+b.y);} 
    friend P operator-(P a,V b){return P(a.x-b.x,a.y-b.y);} 
    friend V operator~(V a){return V(a.y,-a.x);} 
    double dis2(){return x*x+y*y;   }    
}c[MAXN]; 
int cmp(P A,P B) 
{ 
    double tmp=V(a[1],A)*V(a[1],B); 
    if (tmp>0) return 1; 
    else if (fabs(tmp)<eps) return (-dis2(A,a[1])-dis2(B,a[1])>0); 
    return 0; 
} 
int n; 
 
int main() 
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y); 
    for (int i=2;i<=n;i++) if (a[i]<a[1]) swap(a[1],a[i]); 
    sort(a+2,a+1+n,cmp); 
    s[1]=a[1];size=1; 
    for (int i=2;i<=n;) 
        if (size<2||V(s[size-1],s[size])*V(s[size],a[i])>eps) s[++size]=a[i++]; 
        else size--; 
    s[0]=s[size]; 
     
    int l=1,r=1,t=1; 
    for (int i=0;i<size;i++) 
    { 
        while (V(s[i],s[i+1])*V(s[i],s[t+1])-V(s[i],s[i+1])*V(s[i],s[t])>-eps) t=(t+1)%size;  
        while (V(s[i],s[i+1])/V(s[i],s[r+1])-V(s[i],s[i+1])/V(s[i],s[r])>-eps) r=(r+1)%size;  
        if (i==0) l=r; 
        while (V(s[i],s[i+1])/V(s[i],s[l+1])-V(s[i],s[i+1])/V(s[i],s[l])<eps) l=(l+1)%size;  
        double Dis2=dis2(s[i],s[i+1]),wlxdis=V(s[i],s[i+1])/V(s[i],s[l]),wrxdis=V(s[i],s[i+1])/V(s[i],s[r]),hxdis=V(s[i],s[i+1])*V(s[i],s[t]); 
        double tmp=hxdis*(wrxdis-wlxdis)/Dis2;       
        if (tmp<0) tmp=-tmp; 
        if (ans>tmp) 
        { 
            ans=tmp; 
            ansp[0]=s[i]-(wlxdis/Dis2)*V(s[i+1],s[i]); 
            ansp[1]=s[i]+(wrxdis/Dis2)*V(s[i],s[i+1]); 
            ansp[2]=ansp[1]+(hxdis/Dis2)*(~V(s[i+1],s[i]));          
            ansp[3]=ansp[0]+(hxdis/Dis2)*(~V(s[i+1],s[i]));          
        } 
    } 
    int p=0; 
    for (int i=1;i<4;i++) if (ansp[i]<ansp[p]) p=i;//p=0;  
    printf("%.5lf\n",ans);   
    for (int i=0;i<4;i++)  
	  printf("%.5lf %.5lf\n",ansp[(p+i)%4].x,ansp[(p+i)%4].y); 
    return 0; 
} 

