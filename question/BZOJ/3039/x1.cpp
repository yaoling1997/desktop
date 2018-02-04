#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define S int
#define gi gi()
using namespace std;
const S M= 1001;
bool b[M][M];
S H[2][M],L[2][M],R[2][M];
S X[2][M],Y[2][M];
char ch;
S ans,n,m,i,j,x,y,P,Q;
S gi{
	char c= gc;S r= 0;
	while (c<'0'||c>'9') c= gc;
	while (c>='0'&&c<='9') r= r*10+c-'0',c= gc;
	return r;
}
int main()
{
	n= gi;m= gi;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			do ch= gc;
			while (ch!='F'&&ch!='R');
			if (ch=='R') b[i][j]= 1;
		}	
	for (i= 1;i<=m;i++)
		L[0][i]= 0,R[0][i]= m+1,b[0][i]= 1;
	for (i= 1;i<=n;i++){
		P= (i-1)&1;Q= i&1;
		X[Q][0]= 0;Y[Q][m+1]= m+1;
		for (j= 1;j<=m;j++){
			X[Q][j]= X[Q][j-1];
			if (b[i][j]){
				X[Q][j]= j;
				H[Q][j]= 0;
				L[Q][j]= 0;
			}else {
				H[Q][j]= H[P][j]+1;
				L[Q][j]= max(X[Q][j],L[P][j]);
			}
		}
		for (j= m;j>0;j--){
			Y[Q][j]= Y[Q][j+1];
			if (b[i][j]){
				R[Q][j]= m+1;
				Y[Q][j]= j;
			}
			else 
				R[Q][j]= min(Y[Q][j],R[P][j]);
		}
		for (j= 1;j<=m;j++)
			if (R[Q][j]>L[Q][j])
			ans= max(ans,(R[Q][j]-L[Q][j]-1)*H[Q][j]);
	}
	printf("%d\n",3*ans);
	return 0;
}
