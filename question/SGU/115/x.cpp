#include<cstdio>
using namespace std;
int M[20],S[20];
int n,m,sum,i,NN,MM,DD,C;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	NN= 21;MM= 10;DD= 7;
	M[1]= 31;
	M[2]= 28;
	M[3]= 31;
	M[4]= 30;
	M[5]= 31;
	M[6]= 30;
	M[7]= M[8]= 31;
	M[9]= 30;
	M[10]= 31;
	M[11]= 30;
	M[12]= 31;
	for (i= 1;i<=12;i++){
		sum+= M[i];
		S[i]= S[i-1]+M[i];
	}
	if (m<1||m>12||n<1||n>M[m]){
		printf("Impossible\n");
		return 0;
	}
	C= S[m-1]-S[MM-1]+n-NN;
	C= ((C%7)+7)%7;
	if (!C) C= 7;
	printf("%d\n",C);
	return 0;
}
