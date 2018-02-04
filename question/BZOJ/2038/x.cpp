#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 60001;
struct point{
	int x,y,b;
	ll d;
};
point p[maxn];
ll c[maxn];
int a[maxn],stack[maxn],b[maxn],X[maxn];
ll sum;
int n,m,i,j,k,la,x,base;
bool cmp(point a,point b){
	return a.x<b.x ||(a.x==b.x && a.y<b.y);
}
bool cmp1(point a,point b){
	return a.y<b.y || (a.y==b.y && a.x<b.x);
}
bool cmp2(point a,point b){
	return a.b<b.b;
}
void build(int k){
	X[a[k]]= ++la;
	stack[la]= a[k];
	sum-= c[b[a[k]]];
}
void get(){
	while (la){
		sum+= c[b[stack[la]]];
		X[stack[la]]= 0;
		la--;
	}
}
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (ll shit= 1;shit<=n;shit++)
		c[shit]= shit*(shit-1)/2;
	for (i= 1;i<=m;i++){
		scanf("%d %d",&p[i].x, &p[i].y);
		p[i].b= i;
	}
	sort(p+1,p+m+1,cmp);
	base= sqrt(m);
	for (i= 1;i<=m;i+= base){
		x= min(i+base-1,m);
		sort(p+i,p+x+1,cmp1);
		memset(b,0,sizeof(b));sum= 0;
		for (j= p[i].x;j<=p[i].y;j++){
			b[a[j]]++;
			if (!X[a[j]]) build(j);
		}
		get();
		p[i].d= sum;
		for (j= i+1;j<=x;j++){
			if (p[j-1].x>p[j].x){
				for (k= p[j-1].x-1;k>=p[j].x;k--){
					if (!X[a[k]]) build(k);
					b[a[k]]++;
				}
			}else {
				for (k= p[j-1].x;k<p[j].x;k++){
					if (!X[a[k]]) build(k);
					b[a[k]]--;
				}
			}
			if (p[j-1].y<p[j].y){
				for (k= p[j-1].y+1;k<=p[j].y;k++){
					if (!X[a[k]]) build(k);
					b[a[k]]++;
				}
			}else {
				for (k= p[j-1].y;k>p[j].y;k--){
					if (!X[a[k]]) build(k);
					b[a[k]]--;
				}
			}
			get();
			p[j].d= sum;		
		}
	}
	sort(p+1,p+m+1,cmp2);
	for (i= 1;i<=m;i++){
		ll x= p[i].y-p[i].x+1,y;
		x= c[x];y= gcd(p[i].d,x);
		printf("%lld/%lld\n",p[i].d/y,x/y);
	}
	return 0;
}
