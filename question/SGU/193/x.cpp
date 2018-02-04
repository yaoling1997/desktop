#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3;
char s[maxn];
int a[maxn],b[maxn],t[maxn];
int n,m,i,j;
void get(int *a,int n,int x,int y,int *res,int &m){
	memcpy(t,a,sizeof(t));
	t[1]-= x;
	int i;
	for (i= 1;i<=n;i++)
		if (t[i]<0)
			t[i]+= 10,t[i+1]--;
		else break;
	if (!t[n]) n--;
	for (i= n;i>0;i--){
		t[i-1]+= t[i]%y*10;
		t[i]/= y;
	}
	while (n>1&&!t[n])
		n--;
	memcpy(res,t,sizeof(t));
	m= n;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	for (i= 1;i<=n;i++)
		a[n-i+1]= s[i]-'0';
	if (a[1]%2){
		get(a,n,1,2,a,n);
	}else {
		get(a,n,0,2,b,m);
		if (b[1]%2==0)
			get(a,n,2,2,a,n);
		else 
			get(a,n,4,2,a,n);		
	}
	for (i= n;i>0;i--)
		printf("%d",a[i]);
	return 0;
}
