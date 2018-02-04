#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
using namespace std;
const int maxn= 3001;
int a[maxn],b[maxn],c[maxn];
int x,y,i,j,k,ma,mi;
bool bl;
int main()
{
	srand(time(NULL));
	freopen("1.out","w",stdout);
	x= 1;y= 4;
	swap(x,y);
	printf("%d %d\n",x,y);
	for (i= 1;i<=2;i++)
		a[i]= 1;
	for (i= 1;i<=2;i++)
		a[i+2]= 2;
	for (i= 1;i<=2;i++)
		a[i+4]= 3;
	for (i= 1;i<=2;i++)
		a[i+6]= 2;
    j= 8;
	random_shuffle(a+1,a+j+1);
	j= unique(a+1,a+j+1)-a-1;
	reverse(a+1,a+j+1);
	for (i= 1;i<=j;i++) printf("%d ",a[i]);printf("\n");
	ma= *max_element(a+1,a+j+1);
	mi= *min_element(a+1,a+j+1);
	a[++j]= 4;a[++j]= 5;
	sort(a+1,a+j+1);
	x= a[lower_bound(a+1,a+j+1,4)-a];
	y= a[upper_bound(a+1,a+j+1,4)-a];
	printf("%d %d\n",x,y);
	memcpy(b,a,sizeof(a));
	merge(a+1,a+j+1,b+1,b+j+1,c+1);
	printf("%d %d\n",max(ma,mi),min(ma,mi));
	for (i= 1;i<=10;i++)
		c[i]= i;
	bl= prev_permutation(c+1,c+11);
	for (i= 1;i<=10;i++)
		printf("%d ",c[i]);
	if (bl) printf("yes");
	else printf("no");
	printf("\n");
	next_permutation(c+1,c+11);
	bl= next_permutation(c+1,c+11);
	for (i= 1;i<=10;i++)
		printf("%d ",c[i]);
	if (bl) printf("yes");
	else printf("no");
	return 0;
}
