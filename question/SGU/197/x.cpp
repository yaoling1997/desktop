#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1<<6,maxl= 200;
typedef int matrix[maxn][maxn];
typedef int vec[maxn];
char s[maxl];
matrix c,a,res;
vec v;
int b[10][10];
int M,P,n,len,i,ans;
void pre(int x,int y){
	if (y>M){
		x++;
		y= 1;
	}
	if (x==3){
		int i,x= b[1][1],y= b[2][1];
		for (i= 2;i<=M;i++){
			if (b[1][i-1]==b[1][i]&&b[1][i]==b[2][i-1]&&b[2][i-1]==b[2][i]) return;
			x= x*2+b[1][i];
			y= y*2+b[2][i];
		}
		c[x][y]= 1;
		return;
	}
	b[x][y]= 0;
	pre(x,y+1);
	b[x][y]= 1;
	pre(x,y+1);
}
void mul(matrix a,matrix b,matrix res){
	matrix c= {0};
	int i,j,k;
	for (i= 0;i<n;i++)
		for (j= 0;j<n;j++)
			for (k= 0;k<n;k++)
				c[i][j]= (c[i][j]+a[i][k]*b[k][j])%P;
	memcpy(res,c,sizeof(c));
}
void ksm(matrix a,int b,matrix res){
	matrix c= {0},t;
	memcpy(t,a,sizeof(t));
	int i;
	for (i= 0;i<n;i++)
		c[i][i]= 1;
	while (b){
		if (b&1) mul(c,t,c);
		mul(t,t,t);
		b>>= 1;
	}
	memcpy(res,c,sizeof(c));
}
void mul(vec f,matrix a,vec res){
	vec c= {0};
	int i,j;
	for (i= 0;i<n;i++)
		for (j= 0;j<n;j++)
			c[i]= (c[i]+f[j]*a[j][i])%P;
	memcpy(res,c,sizeof(c));
}
void getans(){
	int i;
	ans= 0;
	for (i= 0;i<n;i++)
		ans= (ans+v[i])%P;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s%d%d",s+1, &M, &P);
	len= strlen(s+1);
	reverse(s+1,s+len+1);
	pre(1,1);
	n= 1<<M;
	for (i= 0;i<n;i++){
		v[i]= 1;
		res[i][i]= 1;
	}
	s[1]--;
	for (i= 1;i<=len;i++)
		if (s[i]<'0'){
			s[i]+= 10;
			s[i+1]--;
		}
	while (len>1&&s[len]=='0') len--;
	for (i= 1;i<=len;i++){
		ksm(c,s[i]-'0',a);
		mul(res,a,res);
		ksm(c,10,c);
	}
	mul(v,res,v);
	getans();
	printf("%d\n",ans);
	return 0;
}
