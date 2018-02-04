#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3001;
char s[10][10];
int i,j,k,x,y,z,A,B;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	A= B= 10;
	for (i= 1;i<=8;i++)
		scanf("%s",s[i]+1);
	for (i= 1;i<=8;i++){
		for (j= 1;j<=8;j++){
			if (s[j][i]=='B') break;
			if (s[j][i]=='W'){
				A= min(A,j-1);
				break;
			}
		}
		for (j= 8;j>=1;j--){
			if (s[j][i]=='W') break;
			if (s[j][i]=='B'){
				B= min(B,8-j);
				break;
			}
		}
	}
	if (A<=B) printf("A");
	else printf("B");
	return 0;
}
