#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn= 50001;
int l[maxn],d[maxn];
int ans,n,m,i,x,y,z,now;
int gi(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0'||c>'9')&&c!='-') c= getchar();
	if (c=='-') p= -1,c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
int main()
{
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	//scanf("%d %d",&n, &m);
	n= gi();m= gi();
	for (i= 1;i<=n;i++) //scanf("%d",&d[i]);
		d[i]= gi();
	for (i= 1;i<=n;i++) scanf("%d",&l[i]);
	//l[i]= gi();
	for (int a1= 1;a1<=m;a1++){
		//scanf("%d %d %d",&x, &y, &z);
		x= gi();y= gi();z= gi();
		//x= (x^ans)%n+1;y= (y^ans)%n+1;
		if (x>y) swap(x,y);
		now= z;ans= 0;
		for (i= x;i<=y;i++){
			if (l[i]<now+d[i]) now= l[i];
			else now+= d[i];
			if (now<z) now= z;
			if (ans<now)
				ans= now;
		}	
		printf("%d\n",ans);
	}return 0;
}
