#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e6;
int a[maxn];
int i,n,la;
void insert(int o,int x){
	int i;
	for (i= la;i>=o;i--)
		a[i+1]= a[i];
	a[o]= x;
	la++;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<n;i+= 2)
		a[++la]= i;
	for (i= i-2;i>0;i-= 2)
		a[++la]= i;
	for (i= 2;i<n;i+= 2)
		a[++la]= i;
	for (i= i-2;i>0;i-= 2)
		a[++la]= i;
	/*for (i= 1;i<=la;i++)
		if (a[i]==n-1){
			insert(i,n);
			break;
			}*/
	for (i= 1;i<=la;i++)
		if (a[i]==n-2){
			insert(i+1,n);
			break;
		}
	while (la<2*n)
		a[++la]= n;
	for (i= 1;i<=la;i++)
		printf("%d%c",a[i],i<la?' ':'\n');
	return 0;
}
