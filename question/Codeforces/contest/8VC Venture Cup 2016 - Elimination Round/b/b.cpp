#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e2;
int a[maxn],b[maxn],p[maxn];
char s[maxn],ch[10];
int n,i,j,cnt,q;
bool cmp(int x,int y){
	return a[ch[x]]<a[ch[y]];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	ch[1]= 'B';
	ch[2]= 'G';
	ch[3]= 'R';	
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++)
		a[s[i]]++;
	for (i= 1;i<=3;i++){
		cnt+= a[ch[i]]!=0;
		p[i]= i;
	}
	if (cnt==3) printf("BGR");
	else if (cnt==1){
		for (i= 1;i<=3;i++)
			if (a[ch[i]]) printf("%c",ch[i]);
	}else {
		sort(p+1,p+3+1,cmp);
		if (a[ch[p[2]]]>1) printf("BGR");
		else if (a[ch[p[3]]]>1){
			b[ch[p[3]]]= 1;
			for (i= 1;i<=3;i++)
				if (!b[ch[i]]) printf("%c",ch[i]);
		}else printf("%c",ch[p[1]]);
	}return 0;
}
