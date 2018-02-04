#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 3001;
int f[maxn];
char p[maxn],t[maxn];
int i,j,lent,lenp;
void kmp(){
	f[1]= 0;
	int j= 0,i;
	for (i= 2;i<=lenp;i++){
		while (j>0 && p[j+1]!=p[i])
			j= f[j];
		if (p[j+1]==p[i]) j++;
		f[i]= j;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	bool bl= 0;
	scanf("%s%s",t+1, p+1);
	lent= strlen(t+1);
	lenp= strlen(p+1);
	kmp();
	for (i= 1;i<=lent;i++){
		while (j>0 && p[j+1]!=t[i])
			j= f[j];
		if (p[j+1]==t[i]) j++;
		if (j==lenp){
			printf("%d ",i-j+1);
			bl =1;
			j= f[j];
		}
	}
	if (!bl) printf("Oh shit !");
	return 0;
}
