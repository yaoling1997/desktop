#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1e6;
struct point{
	ll a_b,b_c,a,sta;
	bool operator <(const point &A)const{
		if (a_b<A.a_b) return 1;
		if (a_b>A.a_b) return 0;
		if (b_c<A.b_c) return 1;
		if (b_c>A.b_c) return 0;
		if (a>=A.a) return 1;
		return 0;
	}
};
struct node{
	ll b_c,a,sta;
	bool operator <(const node &a)const{
		return b_c<a.b_c;
	}
};
point A[maxn];
vector<node> v[maxn];
ll l[50],m[50],w[50],a_b[maxn];
ll n,L,M,W,la,top,ans,bl,sta1,sta2,i;
bool cmp(node a,node b){
	return a.b_c<b.b_c||(a.b_c==b.b_c);
}
void dfs(ll o,ll Max,ll a,ll b,ll c,ll sta){
	if (o>Max){
		A[++la]= (point){a-b,b-c,a,sta};
		return;
	}
	ll i,j,cnt= 1,aa,bb,cc;
	for (i= 1;i<3;i++){
		for (j= i+1;j<=3;j++){
			aa= a+(i==1?l[o]:0);
			bb= b+(i==2||j==2?m[o]:0);			
			cc= c+(j==3?w[o]:0);
			dfs(o+1,Max,aa,bb,cc,sta*4+cnt);
			cnt++;
		}
	}
}
void check(ll a,ll b,ll c,ll sta){
	ll x1= b-a,x2= c-b,l= 0,r= top+1;
	while (l+1<r){
		ll mid= (l+r)>>1;
		if (a_b[mid]<=x1) l=mid;
		else r= mid;
	}
	if (l==0||a_b[l]!=x1) return;
	ll i= l;
	l= -1,r= v[i].size();
	//
	while (l+1<r){
		ll mid= (l+r)>>1;
		if (v[i][mid].b_c<=x2) l= mid;
		else r= mid;
	}
	if (l<0||v[i][l].b_c!=x2) return;
	//
	if (!bl||ans<v[i][l].a+a){
		bl= 1;
		ans= v[i][l].a+a;
		sta1= v[i][l].sta;
		sta2= sta;
	}
}
void Dfs(ll o,ll Max,ll a,ll b,ll c,ll sta){
	if (o>Max){
		check(a,b,c,sta);
		return;
	}
	ll i,j,cnt= 1,aa,bb,cc;
	for (i= 1;i<3;i++){
		for (j= i+1;j<=3;j++){
			aa= a+(i==1?l[o]:0);
			bb= b+(i==2||j==2?m[o]:0);
			cc= c+(j==3?w[o]:0);
			Dfs(o+1,Max,aa,bb,cc,sta*4+cnt);
			cnt++;
		}
	}
}
void print(ll o){
	if (!o) return;
	print(o/4);
	ll x= o%4;
	if (x==1) printf("LM\n");
	else if (x==2) printf("LW\n");
	else if (x==3) printf("MW\n");
}
int main()
{
	scanf("%lld",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld%lld%lld",&l[i], &m[i], &w[i]);
	if (n==1){
		L= l[1]==0;
		M= m[1]==0;
		W= w[1]==0;
		if (L+M+W<2) printf("Impossible");
		else {
			if (!L) printf("MW");
			else if (M) printf("LM");
			else printf("LW");
		}
		return 0;
	}
	dfs(1,n/2,0,0,0,0);
	stable_sort(A+1,A+la+1);
	A[0].a_b= A[1].a_b-1;
	for (i= 1;i<=la;i++){
		point u= A[i];
		if (u.a_b!=A[i-1].a_b){			
			top++;
			a_b[top]= u.a_b;
		}else if (u.b_c==A[i-1].b_c) continue;
		v[top].push_back((node){u.b_c,u.a,u.sta});
	}
	Dfs(n/2+1,n,0,0,0,0);
	if (!bl){
		printf("Impossible");
		return 0;
	}
	print(sta1);
	print(sta2);
	return 0;
}
