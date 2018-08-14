#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e5;
char s[maxn];
int bt,et,md;
int len,i,j,a,b,ta,tb,p,q,ans,cnt,now,next,m;
int count1(int x,int y,int p,int q,int cnt){
	if (x>p){
		swap(x,p);
		swap(y,q);
	}
	if (p<y) return 1;
	return 0;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&a, &ta, &b, &tb);
	scanf("%s",s+1);
	p= ((s[1]-'0')*10+s[2]-'0')*60+(s[4]-'0')*10+s[5]-'0';
	q= p+ta;
	bt= 5*60;
	et= 23*60+59;
	md= et+1;
	now= bt;
	cnt= 1;
	while (now<=et){
		next= now+tb;
		ans+= count1(p,q,now,next,cnt);
		now+= b;
	}	
	/*if (q<=md){
		now= bt;
		cnt= 1;
		while (now<=et){
			next= now+tb;
			ans+= count1(p,q,now,next,cnt);
			if (next>md)
				ans+= count1(p,q,0,next-md);			
		}
	}else {
		now= bt;
		cnt= 1;
		q= q-md;
		while (now<=et){
			next= now+tb;
			ans+= count1(p,md,now,next,cnt);
			if (next>md){
				ans+= count1(p,md,0,next-md);
				ans+= count1(md,q,0,next-md);
			}
		}		
		}*/
	printf("%d",ans);
	return 0;
}