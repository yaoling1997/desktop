#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char c[1000];
int a[1000];
int i,x,len,k;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s\n%d",c+1,&x);
	len= strlen(c+1);
	for (i= 1;i<=len;i++)
		a[len-i+1]= c[i]-48;
	k= len;
	for (i= 1;i<=k;i++)
		a[i]*=x;
	for (i= 1;i<=k;i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while (a[k+1]>0){
		k++;
		a[k+1]=a[k]/10;
		a[k]%=10;
	}
	for (i= k;i>0;i--)
		printf("%d",a[i]);
	return 0;	
}
