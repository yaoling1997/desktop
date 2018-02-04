#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 8e6;
typedef ll matrix[4][4];
matrix A,B,D,E,G;
ll F[maxn],f[4],f1[4],vis[maxn],C[maxn],b[maxn];
ll n,sum,N,re;
ll p,K,i,j,x,y,cnt,now,bl,lim;
void mul(matrix a,matrix b,matrix res){
	matrix c;ll i,j,k;
	memset(c,0,sizeof(c));
	for (i= 1;i<=3;i++)
		for (j= 1;j<=3;j++)
			for (k= 1;k<=3;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%p;
	memcpy(res,c,sizeof(c));
}
void pow(matrix A,ll b,matrix res){
	matrix a,t;ll i;
	memset(t,0,sizeof(t));
	memcpy(a,A,sizeof(a));
	for (i= 1;i<=3;i++)
		t[i][i]= 1;
	if (b<0) b= 0;
	while (b){
		if (b&1) mul(t,a,t);
		b>>= 1;mul(a,a,a);
	}memcpy(res,t,sizeof(t));
}
void init(){
	A[1][1]= A[1][2]= A[2][1]= A[3][3]= 1;
	B[1][1]= B[1][2]= B[2][1]= B[3][3]= 1;
	B[3][1]= -1;
	f[1]= f[3]= 1;f[2]= 0;
	f1[1]= 0;f1[2]= 1;f1[3]= 1;
}
void go(ll *f,matrix a,ll *res){
	ll c[4],i,j;
	memset(c,0,sizeof(c));
	for (i= 1;i<=3;i++)
		for (j= 1;j<=3;j++)
			c[i]= (c[i]+f[j]*a[j][i])%p;
	memcpy(res,c,sizeof(c));
}
void Gcd(ll a,ll b){
	if (!b){
		x= 1;y= 0;
		return;
	}Gcd(b,a%b);
	ll t= x;
	x= y;
	y= t-a/b*y;
}
void gcd(ll a,ll b){
	Gcd(a,b);
	if (x<0) x+= K;
}
ll gg(ll a,ll b){
	if (!b) return a;
	return gg(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld %lld",&n, &K, &p);
	init();
	F[1]= F[2]= 1;
	for (i= 3;i<=6*K;i++)
		F[i]= (F[i-1]+F[i-2])%K;
	for (i= 3;i<=6*K;i++)
		if (!vis[F[i]]) vis[F[i]]= i;
	now= 1;
	while (!b[now]){
		if (cnt) b[now]= cnt;
		if (gg(now,K)!=1){
			bl= 1;
			break;
		}
		gcd(now,K);
		if (vis[x])	C[cnt++]= vis[x];
		else {
			bl= 1;
			break;
		}
		now= F[C[cnt-1]-1]*now%K;
		if (cnt>6*K){
			printf("shit!");
			return 0;
		}
	}cnt--;
	if (!bl){
		for (i= 0;i<b[now];i++)
			re+= C[i];
		for (i= b[now];i<=cnt;i++)
			sum+= C[i];
	}else {
		for (i= 0;i<=cnt;i++)
			re+= C[i];
	}
	if (n<=re){
		if (n<=C[0]){
			pow(A,n-1-(n==C[0]),E);
			if (n==C[0]) mul(E,B,E);
			go(f,E,f);
			printf("%lld\n",(f[1]+p)%p);
		}else {
			n-= C[0];
			pow(A,C[0]-2,E);
			mul(E,B,E);
			go(f,E,f);			
			if (bl) lim= cnt;
			else lim= b[now]-1;
			for (i= 1;i<=lim;i++)
				if (n>C[i]){
					pow(A,C[i]-1,E);
					mul(E,B,E);
					go(f,E,f);
					n-= C[i];
				}else {
					pow(A,n-(n==C[i]),E);
					if (n==C[i]) mul(E,B,E);
					go(f,E,f);
					break;
				}
			printf("%lld",(f[1]+p)%p);
		}
		return 0;
	}else {
		pow(A,C[0]-2,E);
		mul(E,B,E);
		go(f,E,f);
		if (bl) lim= cnt;
		else lim= b[now]-1;
		for (i= 1;i<=lim;i++){
			pow(A,C[i]-1,E);
			mul(E,B,E);
			go(f,E,f);
		}
		memcpy(f1,f,sizeof(f));
		go(f,A,f);
		n-= re;
		if (!bl){
			for (i= 1;i<=cnt;i++)
				C[i]= C[i+b[now]-1];
			cnt-= b[now]-1;
		}
	}
	D[1][1]= D[2][2]= D[3][3]= 1;
	G[1][1]= G[2][2]= G[3][3]= 1;
	if (!bl){
		N= n%sum;
		if (!N) memcpy(f,f1,sizeof(f));
		for (i= 1;i<=cnt;i++)
			if (N>C[i]) N-= C[i];
			else break;
		if (N!=C[i]){
			pow(A,C[i]-N-1,E);
			mul(D,E,D);
			mul(D,B,D);
		}
		for (j= i+1;j<=cnt;j++){
			pow(A,C[j]-1,E);
			mul(D,E,D);
			mul(D,B,D);
		}
		for (j= 1;j<i;j++){
			pow(A,C[j]-1,E);
			mul(D,E,D);
			mul(D,B,D);
		}
		pow(A,N-(N==C[i]),E);
		mul(D,E,D);
		if (N==C[i]) mul(D,B,D);
		pow(D,n/sum,D);	
		if (i!=1){
			pow(A,C[1]-2,E);
			mul(G,E,G);
			mul(G,B,G);
			for (j= 2;j<i;j++){
				pow(A,C[j]-1,E);
				mul(G,E,G);
				mul(G,B,G);
			}
			pow(A,N-(N==C[i]),E);
			mul(G,E,G);
			if (N==C[i]) mul(G,B,G);
		}else {
			pow(A,N-1-(N==C[1]),E);
			mul(G,E,G);
			if (N==C[1]) mul(G,B,G);
		}
		go(f,G,f);
		go(f,D,f);
	}else {
		N= n;
		/*for (i= 1;i<=cnt;i++)
			if (N>C[i]) N-= C[i];
			else break;			
		if (i<=cnt){
			if (i!=1){
				pow(A,C[1]-2,E);
				mul(G,E,G);
				mul(G,B,G);
				for (j= 2;j<i;j++){
					pow(A,C[j]-1,E);
					mul(G,E,G);
					mul(G,B,G);
				}
				pow(A,N-(N==C[i]),E);
				mul(G,E,G);
				if (N==C[i]) mul(G,B,G);
			}else {
				pow(A,N-1-(N==C[1]),G);
				if (N==C[1]) mul(G,B,G);				
			}go(f,G,f);
		}else {
			if (cnt){
				pow(A,C[1]-2,E);
				mul(G,E,G);
				mul(G,B,G);
			}else N--;
			for (i= 2;i<=cnt;i++){
				pow(A,C[i]-1,E);
				mul(G,E,G);
				mul(G,B,G);
				}*/
			pow(A,N-1,E);
			mul(G,E,G);
			go(f,G,f);
			//}
	}
	printf("%lld\n",(f[1]+p)%p);
	return 0;	
}
