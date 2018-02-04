#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
struct bi{
	int a[maxn];
	int k;
	void mt(){
		for (int i= 1;i<=k;i++){
			a[i+1]+= a[i]/10;
			a[i]%= 10;
		}
		while (a[k+1]){
			k++;
			a[k+1]+= a[k]/10;
			a[k]%= 10;
		}
	}
	bi():k(1){}
};
char s[maxn];
int S[maxn];
bi a,b,c;
int n,la,p,k,i;
int sqr(int x){
	return x*x;
}
void mul(bi &a,int x){
	int i;
	for (i= 1;i<=a.k;i++)
		a.a[i]*= x;
	a.mt();
}
void add(bi &a,int x){
	a.a[1]+= x;
	a.mt();
}
void copy(bi &b,bi &a){
	memcpy(b.a,a.a,sizeof(a.a));
	b.k= a.k;
}
bool big(bi &a,bi &b){
	if (a.k>b.k) return 1;
	if (a.k<b.k) return 0;
	for (int i= a.k;i>0;i--)
		if (a.a[i]>b.a[i]) return 1;
		else if (a.a[i]<b.a[i]) return 0;
	return 0;
}
void del(bi &a,bi &b){
	int i;
	for (i= 1;i<=b.k;i++){
		a.a[i]-= b.a[i];
		if (a.a[i]<0){
			a.a[i]+= 10;
			a.a[i+1]--;
		}
	}
	while (a.k>1&&a.a[a.k]==0)
		a.k--;	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	s[0]= '0';
	for (i= n;i>0;i-= 2)
		S[++la]= (s[i-1]-'0')*10+s[i]-'0';
	p= la;
	for (a.a[1]= 0;a.a[1]<=9&&sqr(a.a[1]+1)<=S[p];a.a[1]++);
	b.a[1]= S[p]-a.a[1]*a.a[1];
	b.mt();
	for (p--;p>0;p--){
		mul(b,100);
		add(b,S[p]);
		for (i= 0;i<=9;i++){
			copy(c,a);
			mul(c,20);
			add(c,i+1);			
			mul(c,i+1);
			if (big(c,b)) break;
		}
		copy(c,a);
		mul(c,20);
		add(c,i);
		mul(c,i);
		del(b,c);
		mul(a,10);
		a.a[1]= i;
	}
	for (i= a.k;i>0;i--)
		printf("%d",a.a[i]);
}
