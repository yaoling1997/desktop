#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 1e6+10;
int p[maxn];
int N,A,B,a,b,bl;
void rotate(int l,int r){
	int t=p[l];
	for (int i=l;i<r;i++)
		p[i]=p[i+1];
	p[r]=t;
}
void solve(){
	for (int i=1;i<=N;i++)
		p[i]=i;
	int now=1;
	while (a){
		a--;
		rotate(now,now+A-1);
		now+=A;
	}
	while (b){
		b--;
		rotate(now,now+B-1);
		now+=B;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&N, &A, &B);
	for (a=0;a*A<=N;a++)
		if ((N-a*A)%B==0){
			bl=true;
			b=(N-a*A)/B;
				break;
		}
	if (!bl){
		printf("-1");
	}else {
		solve();
		for (int i=1;i<=N;i++)
			printf("%d%c",p[i],i<N?' ':'\n');		
	}
	return 0;
}
