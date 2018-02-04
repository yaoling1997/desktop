#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<cctype>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn= 20000001,maxm= 110000,base= 251;
//const int maxn= 20001,maxm= 1100,base= 251;
ull h[maxn],d[maxn];
char str[maxn],st[maxn];
int cnt[maxm],from[maxm],to[maxm];
char ch;
int T,n,i,bl,com,nowlen,now;
bool ok(char c){
	return isdigit(c)||isalpha(c)||c=='*';
}
ull gethash(int a,int b){
	a--;
	return h[b]-h[a]*d[b-a];
}
bool right(int a,int b){
	int l= from[a],r= to[a],L= from[b],R= to[b];
	while (l<=r&&L<=R&&str[l]!='*')
		if (str[l]==str[L])
			l++,L++;
		else return 0;
	while (l<=r&&L<=R&&str[r]!='*')
		if (str[r]==str[R])
			r--,R--;
		else return 0;
	while (l<=r){
		while (l<=r&&str[l]=='*') l++;
		if (l>r) return 1;
		int i,len;
		for (i= l;i<=r&&str[i]!='*';i++);
		len= i-l;
		for (;L<=R;L++){
			if (L+len-1>R) return 0;
			if (gethash(l,i-1)==gethash(L,L+len-1)) break;
		}if (L+len-1>R) return 0;
		L+= len;l= i;
	}return 1;
}
bool check(){
	if (com!=-1){
		for (i= 1;i<=n;i++){
			if (cnt[i]>cnt[com]) return 0;
			if (cnt[i]==to[i]-from[i]+1&&(cnt[i]!=cnt[com]||gethash(from[i],to[i])!=gethash(from[com],to[com]))) return 0;
			if (cnt[i]!=to[i]-from[i]+1&&!right(i,com)) return 0;
		}
		return 1;
	}else {
		int i,j,len= 0;
		for (i= from[1];i<=to[1]&&str[i]!='*';i++)
			st[++len]= str[i];
		for (i= 2;i<=n;i++)
			for (j= from[i];j<=to[i]&&str[j]!='*';j++){
				if (len>=j-from[i]+1){
					if (str[j]!=st[j-from[i]+1]) return 0;
				}else st[++len]= str[j];
			}
		len= 0;
		for (i= to[1];i>=from[1]&&str[i]!='*';i--)
			st[++len]= str[i];
		for (i= 2;i<=n;i++)
			for (j= to[i];j>=from[i]&&str[j]!='*';j--){
				if (len>=to[i]-j+1){
					if (str[j]!=st[to[i]-j+1]) return 0;
				}else st[++len]= str[j];
			}
		return 1;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		now= 0;com= -1;
		for (i= 1;i<=n;i++){
			bl= 0;cnt[i]= 0;			
			for (ch= getchar();ch=='\n'||ch=='\r';ch= getchar());
			str[from[i]= ++now]= ch;
			if (ch=='*') bl= 1;
			else cnt[i]++;			
			for (ch= getchar();ok(ch);ch= getchar()){
				str[++now]= ch;
				if (ch=='*') bl= 1;
				else cnt[i]++;
			}to[i]= now;
			if (!bl) com= i;
		}
		d[0]= 1;
		if (nowlen<now)
			for (i= nowlen+1;i<=now;i++)
				d[i]= d[i-1]*base;
		nowlen= max(nowlen,now);
		for (i= 1;i<=now;i++)
			h[i]= h[i-1]*base+str[i];
		bl= check();
		printf("%c\n",bl?'Y':'N');
	}return 0;
}
