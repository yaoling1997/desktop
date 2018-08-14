#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e6,maxm= 3e7;
int ch[maxm][2],v[maxm],a[maxn],s[maxn];
ll ans;
int n,K,i,j,x,y,z,Max,tot;
void update(int x,int &re){
	int cnt= 0;
	while (x){
		cnt++;
		x>>= 1;
	}re= max(re,cnt);
}
void insert(int x){
	int d[50]= {0},i,now= 0;
	for (i= 1;i<=Max;i++){
		d[i]= x&1;
		x>>= 1;
	}
	for (i= Max;i>0;i--){
		if (!ch[now][d[i]]) ch[now][d[i]]= ++tot;
		now= ch[now][d[i]];
		v[now]++;
	}
}
int find(int V,int K){
	int P[50]= {0},Q[50]= {0},i,now= 0,re= 0;
	for (i= 1;i<=Max;i++){
		P[i]= V&1;
		Q[i]= K&1;
		V>>= 1;
		K>>= 1;
	}	
	for (i= Max;i>0;i--){
		int x= P[i],y= Q[i],z= x^y;
		if (y==1);
		else re+= v[ch[now][z^1]];			
		now= ch[now][z];
		if (!now) break;
	}
	if (now) re+= v[now];
	return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &K);
	Max= 1;
	update(K,Max);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]= s[i-1]^a[i];
		update(s[i],Max);
	}
	insert(0);	
	for (i= 1;i<=n;i++){
		ans+= find(s[i],K);
		insert(s[i]);
	}printf("%I64d\n",ans);
	return 0;
}
