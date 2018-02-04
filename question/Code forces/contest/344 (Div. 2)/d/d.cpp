#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
const ull bs= 37,bd= 101;
const int maxn= 3e5;
ull tsh[maxn],tdh[maxn],dc[maxn],dd[maxn];
char s[200],tc[maxn],sc[maxn];
ll td[maxn],sd[maxn];
ull ssh,sdh;
ll ans;
char ch;
int n,m,i,j,x,y,cnt;
void get(char *s,ll &x,char &ch){
	int len= strlen(s+1),i;
	x= 0;
	for (i= 1;i<=len;i++){
		if (s[i]=='-') break;
		x= x*10+s[i]-'0';
	}
	ch= s[i+1];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	cnt= 0;
	dc[0]= dd[0]= 1;
	for (i= 1;i<=n;i++){
		dc[i]= dc[i-1]*bs;
		dd[i]= dd[i-1]*bd;
		cnt++;
		scanf("%s",s+1);
		get(s,td[cnt],tc[cnt]);
		if (tc[cnt]==tc[cnt-1]){
			td[cnt-1]+= td[cnt];
			cnt--;
		}
	}n= cnt;
	cnt= 0;
	for (i= 1;i<=m;i++){
		cnt++;
		scanf("%s",s+1);
		get(s,sd[cnt],sc[cnt]);
		if (sc[cnt]==sc[cnt-1]){
			sd[cnt-1]+= sd[cnt];
			cnt--;
		}
	}m= cnt;
	if (m==1){
		for (i= 1;i<=n;i++)
			if (tc[i]==sc[1]&&td[i]>=sd[1])
				ans+= td[i]-sd[1]+1;
	}else {
		for (i= 1;i<=n;i++){
			tsh[i]= tsh[i-1]*bs+tc[i]-'a';
			tdh[i]= tdh[i-1]*bd+td[i];
		}
		for (i= 2;i<m;i++){
			ssh= ssh*bs+sc[i]-'a';
			sdh= sdh*bd+sd[i];
		}
		for (i= 1;i+m-1<=n;i++)
			if (tc[i]==sc[1]&&tc[i+m-1]==sc[m])
				if (td[i]>=sd[1]&&td[i+m-1]>=sd[m])
					if (tsh[i+m-2]-tsh[i]*dc[m-2]==ssh)
						if (tdh[i+m-2]-tdh[i]*dd[m-2]==sdh)
							ans++;
	}
	printf("%lld",ans);
	return 0;
}
