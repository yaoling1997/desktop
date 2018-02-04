#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 150003;
struct rec{
	int x,y;
};
rec a[maxn];
int heap[maxn];
int top,n,i,m;
void up(int o){
	while (o/2>0 && heap[o/2]<heap[o]){
		int t= heap[o/2];
		heap[o/2]= heap[o];
		heap[o]= t;
		o/= 2;
	}
}
void down(int o){
	int g= o;
	if (2*o<=top && heap[2*o]>heap[g]) g= 2*o;
	if (2*o+1<=top && heap[2*o+1]>heap[g]) g= 2*o+1;
	if (g!=o){
		int t= heap[g];
		heap[g]= heap[o];
		heap[o]= t;
		down(g);
	}
}
bool cmp(rec a,rec b){return a.x<b.x;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
		
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++)	scanf("%d %d\n",&a[i].y,&a[i].x);
	sort(a+1,a+n+1,cmp);
	m= 0;top= 0;
	for (i= 1;i<=n;i++){
		if (m+a[i].y<=a[i].x) {
			m+= a[i].y;
			top++;
			heap[top]= a[i].y;
			up(top);
		}else if (heap[1]>a[i].y){
				m+= a[i].y-heap[1];
				heap[1]= a[i].y;
				down(1);
		}
	}
	printf("%d",top);
	return 0;	
}
