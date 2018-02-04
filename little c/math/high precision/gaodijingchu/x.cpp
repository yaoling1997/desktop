#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[1000];
int n,i,x,p,q,len,k;
char c[1000];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s\n%d",c+1,&x);
	len= strlen(c+1);
	for (i= 1;i<=len;i++)
		a[len-i+1]= c[i]-48;
	k= len;
	for (i= k;i>0;i--){
		q= (a[i]+p*10)%x;
		a[i]= (a[i]+p*10)/x;
		p= q;
	}
	while (a[k]==0 && k>1) k--;
	for (i= k;i>0;i--)
		printf("%d",a[i]);
	return 0;	
}
