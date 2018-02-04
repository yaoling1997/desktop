#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 300001;
const ll mo= 1073741824;
struct node{
	ll x,y,z,b;
};
node p[maxn];
int f[maxn];
ll g[maxn],tt[maxn],tr[maxn];
ll v,su,re,ss,sum[maxn];
int i,n,tot,time,ans;
bool cmpx(node a,node b){return a.x<b.x||
		(a.x==b.x && a.y<b.y)||(a.x==b.x && a.y==b.y && a.z<b.z);}
bool cmpy(node a,node b){return a.y<b.y;}
bool cmpz(node a,node b){return a.z<b.z;}
int lowbit(int o){return o&(-o);}
void change(int o,int x,ll d){
	while (o<=n){
		if (tr[o]<x || tt[o]!=time){
			tt[o]= time;
			tr[o]= x;
			sum[o]= d;
		}else if (tr[o]==x) sum[o]+= d;
		o+= lowbit(o);
	}
}
void ask(int o){
	re= ss= 0;
	while (o){
		if (re<tr[o] && tt[o]==time){re= tr[o];ss= sum[o];}
		else if (re==tr[o] && tt[o]==time) ss+= sum[o];
		o-= lowbit(o);
	}
}
void merge(int l,int r){
	if (l>=r) return;
	int mid= (l+r)>>1,i,j;
	merge(l,mid);
	sort(p+l,p+mid+1,cmpy);
	sort(p+mid+1,p+r+1,cmpy);
	j= l;time++;
	for (i= mid+1;i<=r;i++){
		while (j<=mid && p[j].y<=p[i].y){
			change(p[j].z,f[p[j].b],g[p[j].b]);
			j++;
		}
		ask(p[i].z);
		if (f[p[i].b]<re+1){f[p[i].b]= re+1;g[p[i].b]= ss;}
		else if (f[p[i].b]==re+1) g[p[i].b]+= ss;
	}
	sort(p+l,p+mid+1,cmpx);
	sort(p+mid+1,p+r+1,cmpx);
	merge(mid+1,r);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld %lld %lld",&p[i].x, &p[i].y, &p[i].z);
		p[i].b= i;
	}
	sort(p+1,p+n+1,cmpx);
	tot= 1;v= p[1].x;
	for (i= 1;i<=n;i++)
		if (p[i].x==v) p[i].x= tot;
		else {
			v= p[i].x;
			p[i].x= ++tot;
		}
	sort(p+1,p+n+1,cmpy);
	tot= 1;v= p[1].y;
	for (i= 1;i<=n;i++)
		if (p[i].y==v) p[i].y= tot;
		else {
			v= p[i].y;
			p[i].y= ++tot;
		}
	sort(p+1,p+n+1,cmpz);
	tot= 1;v= p[1].z;
	for (i= 1;i<=n;i++)
		if (p[i].z==v) p[i].z= tot;
		else {
			v= p[i].z;
			p[i].z= ++tot;
		}
	sort(p+1,p+n+1,cmpx);
	for (i= 1;i<=n;i++)
		f[i]= g[i]= 1;
	merge(1,n);su= 0;
	for (i= 1;i<=n;i++)
		if (f[ans]<f[i]){
			ans= i;su= g[i];
		}else if (f[ans]==f[i])
			su+= g[i];
	printf("%d %lld\n",f[ans],su%mo);
	return 0;
}
