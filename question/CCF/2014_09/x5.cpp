#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int mo= 1000000007;
const int maxn= 10,maxm= 140;
typedef int matrix[maxm][maxm];
typedef int vec[maxm];
matrix a,o;
vec f;
int d[maxn],b[maxn],c[maxn];
ll n;
int m,i,M;
bool ok(int o,int *b){
	return 0<=o&&o<m&&!b[o];
}
bool check(){
	int i;
	for (i= 0;i<m;i++)
		if (!b[i])
			return 0;
	return 1;
}
void put(int o,int B){
	if (o==m){
		if (check()){
			int C= 0,i;
			for (i= 0;i<m;i++)
				C= C*2+c[i];
			a[B][C]++;
		}
		return;
	}
	put(o+1,B);
	if (ok(o,b)&&ok(o+1,b)&&ok(o,c)){
		b[o]= b[o+1]= 1;
		c[o]= 1;
		put(o+1,B);
		b[o]= b[o+1]= 0;
		c[o]= 0;
	}
	if (ok(o,b)&&ok(o+1,b)&&ok(o+1,c)){
		b[o]= b[o+1]= 1;
		c[o+1]= 1;
		put(o+1,B);
		b[o]= b[o+1]= 0;
		c[o+1]= 0;
	}
	if (ok(o+1,b)&&ok(o,c)&&ok(o+1,c)){
		b[o+1]= 1;
		c[o]= c[o+1]= 1;
		put(o+1,B);
		b[o+1]= 0;
		c[o]= c[o+1]= 0;
	}
	if (ok(o,b)&&ok(o,c)&&ok(o+1,c)){
		b[o]= 1;
		c[o]= c[o+1]= 1;
		put(o+1,B);
		b[o]= 0;
		c[o]= c[o+1]= 0;
	}
}
void init(int o){
	if (o==m){
		int x= 0,i;
		for (i= 0;i<m;i++)
			x= x*2+b[i];
		put(0,x);
		return;
	}
	b[o]= 0;
	init(o+1);
	b[o]= 1;
	init(o+1);
}
void update(int &F,int x){
	F+= x;
	if (F>=mo) 
		F-= mo;
}
void mul(matrix a,matrix b,matrix res){
	matrix c= {0};
	int i,j,k;
	for (i= 0;i<M;i++)
		for (j= 0;j<M;j++)
			for (k= 0;k<M;k++){
				int x= (ll)a[i][k]*b[k][j]%mo;
				update(c[i][j],x);
			}
	memcpy(res,c,sizeof(c));
}
void ksm(matrix A,ll b,matrix res){
	matrix t= {0};
	matrix a;
	memcpy(a,A,sizeof(a));
	int i;
	for (i= 0;i<M;i++)
		t[i][i]= 1;
	while (b){
		if (b&1)
			mul(t,a,t);
		mul(a,a,a);
		b>>= 1;
	}
	memcpy(res,t,sizeof(t));
}
void mul(vec f,matrix a,vec res){
	vec c= {0};
	int i,j;
	for (i= 0;i<M;i++)
		for (j= 0;j<M;j++){
			int x= (ll)f[j]*a[j][i]%mo;
			update(c[i],x);
		}			
	memcpy(res,c,sizeof(c));
}
void print(matrix a){
	int i,j;
	for (i= 0;i<M;i++)
		for (j= 0;j<M;j++)
			printf("%d%c",a[i][j],j<M-1?' ':'\n');		
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n>>m;
	d[0]= 1;
	for (i= 1;i<=m;i++)
		d[i]= d[i-1]*2;
	M= d[m];
	if (n==1||m==1){
		printf("0");
		return 0;
	}
	init(0);
	//print(a);
	//return 0;
	f[M-1]= 1;
	ksm(a,n,a);
	/*for (i= 0;i<M;i++)
		o[i][i]= 1;
	for (i= 1;i<=n;i++)
		mul(o,a,o);
	mul(f,o,f);*/
	mul(f,a,f);
	printf("%d",f[M-1]);
	return 0;
}

