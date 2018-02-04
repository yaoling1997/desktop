#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define gc getchar
using namespace std;
const int maxn= 1e6;
int X[110][100010];
int F[maxn],F2[maxn],B[maxn],B2[maxn],C[maxn],f[maxn],f2[maxn];
int n,d,K,i,j,k,p,cnt,x,y,z,dd;
int random(int o){return rand()%o;}
void init(){
	for (int i= 0;i<=n;i++) B[i]= B2[i]= 0;
	p= 0;
}
void read(int &a){
	char c= gc();a= 0;
	while (c<'0'||c>'9') c= gc();
	while ('0'<=c&&c<='9') a= a*10+c-'0',c= gc();
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &d, &K);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=d;j++){
			read(X[j][i]);
			X[j][i]%= K;
		}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=d;j++)
			C[i]= (C[i]+X[j][i]*X[j][i])%K;
	if (K==2){
		for (i= 1;i<=n;i++) F[i]= F2[i]= 1;
		cnt++;
		init();
		for (i= 1;i<=d;i++)
			for (j= 1;j<=n;j++)
				B[i]= (B[i]+F[j]*X[i][j])&1;
		for (i= 1;i<=n;i++) F[i]= 0;
		for (i= 1;i<=n;i++)
			for (j= 1;j<=d;j++)
				F[i]= (F[i]+B[j]*X[j][i])&1;
		for (i= 1;i<=n;i++)
			B2[i]= F2[i]*(C[i]+n-1)&1;
		for (i= 1;i<=n;i++)
			if (F[i]!=B2[i]){
				p= i;
				break;
			}
		if (p){
			for (i= 1;i<=n;i++)
				if (i!=p){
					z= 0;
					for (j= 1;j<=d;j++)
						z= (z+X[j][i]*X[j][p])&1;
					if (!z){
						printf("%d %d\n",min(p,i),max(p,i));
						return 0;
					}
				}
			for (i= 1;i<=n;i++) F[i]= F2[i]= random(2);			
		}
		printf("-1 -1");
	}else {
		for (i= 1;i<=n;i++)
			C[i]= C[i]*C[i]%K;
		for (i= 1;i<=n;i++) F[i]= F2[i]= 1;
		cnt++;
		init();
		for (x= 1;x<=d;x++)
			for (y= 1;y<=d;y++)
				for (j= 1;j<=n;j++)
					B[(x-1)*d+y]= (B[(x-1)*d+y]+F[j]*X[x][j]*X[y][j])%K;
		for (i= 1;i<=n;i++) F[i]= 0;
		for (i= 1;i<=n;i++)
			for (x= 1;x<=d;x++)
				for (y= 1;y<=d;y++)
					F[i]= (F[i]+B[(x-1)*d+y]*X[x][i]*X[y][i])%K;
		for (i= 1;i<=n;i++)
			B2[i]= F2[i]*(C[i]+n-1)%K;
		for (i= 1;i<=n;i++)
			if (F[i]!=B2[i]){
				p= i;
				break;
			}
		if (p){
			for (i= 1;i<=n;i++)
				if (i!=p){
					z= 0;
					for (x= 1;x<=d;x++)
						for (y= 1;y<=d;y++)
							z= (z+X[x][i]*X[y][i]*X[x][p]*X[y][p])%K;
					if (!z){
						printf("%d %d\n",min(p,i),max(p,i));
						return 0;
					}
				}
			for (i= 1;i<=n;i++) F[i]= F2[i]= random(3);			
		}
		printf("-1 -1");		
	}return 0;
}
