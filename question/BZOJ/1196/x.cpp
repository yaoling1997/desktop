#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define Q short
using namespace std;
const Q maxn= 10010,maxm= 20010;
struct rec{
	Q x,y,z;
};
rec a[maxm],b[maxm];
Q f[maxn];
Q i,j,n,k,m,x,y,c1,c2,s,g;
bool cmp(rec a,rec b){return a.z<b.z;}
Q find(int o){
	if (o==f[o]) return f[o];
	f[o]= find(f[o]);
	return f[o];
}
Q get(){
	char ch= getchar();Q re= 0;
	while (ch<'0' || ch>'9') ch= getchar();
	while (ch>='0' && ch<='9'){re= re*10+ch-'0';ch= getchar();}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= get();k= get();m= get();
	for (i= 1;i<=m-1;i++){
		a[i].x= get();
		a[i].y= get();
		a[i].z= get();
		b[i].z= get();
		b[i].x= a[i].x;
		b[i].y= a[i].y;
	}
	sort(a+1,a+m,cmp);
	sort(b+1,b+m,cmp);
	for (i= 1;i<=n;i++) f[i]= i;
	if (k!=0)
		for (i= 1;i<=m-1;i++){
			x= a[i].x;y= a[i].y;
			f[x]=find(f[x]);f[y]= find(f[y]);
			if (f[x]!=f[y]){
				f[f[x]]= f[y];
				g++;
				if (g==k) break;
			}
		}
	j= a[i].z;
	if (g==k){
		for (i= 1;i<=m-1;i++){
			x= b[i].x;y= b[i].y;
			f[x]=find(f[x]);f[y]= find(f[y]);
			if (f[x]!= f[y]){
				f[f[x]]= f[y];
				g++;
				if (g==n-1) break;
			}
		}
	}
	i= b[i].z;
	printf("%d",max(i,j));
	return 0;
}

