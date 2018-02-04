#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int maxl= 10,maxm= 7e5;
map<int,int> M;
char s[maxl];
int a[20][maxm],d[20];
int n,m,i,j,k,x,y,sum,w,S,L,R,ans;
int lowbit(int o){
	return o & -o;
}
void change(int x,int o,int d){
	o++;
	while (o<=m){
		a[x][o]+= d;
		o+= lowbit(o);
	}
}
int find(int x,int o){
	o++;int re= 0;
	while (o){
		re+= a[x][o];
		o-= lowbit(o);
	}return re;
}
int main()
{
	scanf("%d",&n);
	m= (1<<16)+1;
	d[0]= 1;
	for (i= 1;i<=16;i++)
		d[i]= d[i-1]*2+1;
	for (int N= 1;N<=n;N++){
		scanf("%s%d",s+1, &x);
		if (s[1]=='I'){
			x-= sum;
			M[x]++;
			for (i= 0;i<=15;i++)
				change(i,x&d[i],1);
		}else if (s[1]=='D'){
			x-= sum;
			w= M[x];M[x]= 0;
			if (!w) continue;
			for (i= 0;i<=15;i++)
				change(i,x&d[i],-w);
		}else if (s[1]=='A'){
			sum+= x;
		}else {
			S= sum&d[x];
			L= 1<<x,R= d[x];
			L-= S;R-= S;
			ans= 0;
			if (L>=0)
				ans= find(x,R)-find(x,L-1);
			else {
				ans= find(x,R)-find(x,-1);
				ans+= find(x,-1&d[x])-find(x,(L&d[x])-1);
			}
			printf("%d\n",ans);
		}
	}return 0;
}
