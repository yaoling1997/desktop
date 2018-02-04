#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 50005;
ll c[maxn],f[maxn];
int q1[maxn],q2[maxn],stack[maxn];
int n,L,i,top,bot,j;
ll count(int i,int j){
	int x= (i-j-1+c[i]-c[j]-L);
	return f[j]+(ll)x*x;
}
void update(int k){
	int i,j;
	if (q2[bot]<=k) bot++;
	while (top>=bot){
		i= q1[top]= max(q1[top],k+1);j= stack[top];
		if (count(i,k)<count(i,j)) top--;
		else {
			int l= q1[top],r= q2[top]+1;
			while (l+1<r){
				int mid= l+((r-l)>>1);
				if (count(mid,k)<count(mid,j)) r= mid;
				else l= mid;
			}
			q2[top]= l;break;
		}
	}
	if (q2[top]!=n)
		stack[++top]= k,q1[top]= max(q2[top-1]+1,k+1),q2[top]= n;
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0' || c>'9') c= getchar();
	while (c>='0' && c<='9'){re= re*10+c-'0';c= getchar();}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= getint();L= getint();
	for (i= 1;i<=n;i++){
		c[i]= getint();
		c[i]+= c[i-1];
	}
	stack[bot= ++top]= 0;q1[1]= 1;q2[1]= n;
	for (i= 1;i<=n;i++){
		int j= stack[bot];
		f[i]= count(i,j);
		if (n-i)
		update(i);
	}
	printf("%lld",f[n]);
	return 0;
}
