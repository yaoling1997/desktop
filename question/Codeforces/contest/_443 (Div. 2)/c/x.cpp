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
const int maxn= 6e5;
char s[maxn][3];
int b[maxn][10];
int n,i,j;
int solve(int o,int v){
	for (int i= 1;i<=n;i++)
		if (s[i][0]=='|'){
			o|= b[i][v];
		}else if (s[i][0]=='^'){
			o^= b[i][v];
		}else {
			o&= b[i][v];
		}
	return o;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		int x;
		scanf("%s%d",s[i], &x);
		for (j= 0;j<10;j++){
			b[i][j]= x&1;
			x>>= 1;
		}
	}
	int A= 0,B= 0,C= 0;
	for (i= 9;i>=0;i--){
		int x= solve(0,i);
		int y= solve(1,i);
		x= x*2+y;
		if (x==0){
			A= A*2;
			B= B*2;
			C= C*2;
		}else if (x==1){
			A= A*2+1;
			B= B*2;
			C= C*2;
		}else if (x==2){
			A= A*2+1;
			B= B*2+1;
			C= C*2;
		}else {
			A= A*2+1;
			B= B*2;
			C= C*2+1;
		}
	}
	printf("3\n& %d\n^ %d\n| %d",A, B, C);
	return 0;
}
