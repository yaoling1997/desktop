#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 10011,base= 1e8,lim= 8;
struct node{
	int a[maxn];
	int k;
	void update(){
		while (a[k+1]){
			k++;
			a[k+1]= a[k]/base;
			a[k]%= base;
		}while (k>1&&!a[k]) k--;
	}
	bool operator !=(const node &b)const{
		if (b.k!=k) return 1;
		for (int i= 1;i<=k;i++)
			if (b.a[i]!=a[i]) return 1;
		return 0;
	}
	bool operator <(const node &b)const{
		if (b.k>k) return 1;
		else if (b.k<k) return 0;
		for (int i= k;i>=1;i--)
			if (b.a[i]>a[i]) return 1;
			else if (b.a[i]<a[i]) return 0;
		return 0;
	}
	void operator /=(const int x){
		int p= 0,q= 0;
		for (int i= k;i>0;i--){
			q= (p*base+a[i])%x;
			a[i]= (p*base+a[i])/x;
			p= q;
		}update();
	}
	void operator -=(const node &b){
		for (int i= 1;i<=b.k;i++){
			a[i]-= b.a[i];
			if (a[i]<0)
				a[i]+= base,a[i+1]--;
		}update();			
	}
	void operator *=(const int x){
		int i;
		for (i= 1;i<=k;i++) a[i]*= x;
		for (i= 1;i<=k;i++)
			a[i+1]+= a[i]/base,a[i]%= base;
		update();
	}
};
node a,b;
char s[maxn];
int d[maxn];
int i,j;
void get(node &a){
	int i,len,cnt= 0,sum= 0;
	len= strlen(s+1);
	for (i= len;i>=1;i--){
		sum+= (s[i]-'0')*d[cnt];
		cnt++;
		if (cnt==lim)
			a.a[++a.k]= sum,sum= cnt= 0;
	}if (cnt)
		 a.a[++a.k]= sum;
}
bool ok(node &a){
	int p= 0,i;
	for (i= a.k;i>0;i--)
		p= (p*base+a.a[i])%2;
	return !p;
}
void print(node &a){
	int i,k= a.k,x,y;
	printf("%d",a.a[k]);
	for (i= k-1;i>=1;i--){
		x= a.a[i];y= 0;
		while (x){
			x/= 10;
			y++;
		}if (!y) y= 1;
		while (y<lim){
			printf("0");
			y++;
		}printf("%d",a.a[i]);
	}
}
void gcd(node &a,node &b){
	int cnt= 0,A,B;
	while (a!=b){
		if (a<b) swap(a,b);
		A= (a.a[1]&1)==0;
		B= (b.a[1]&1)==0;
		if (A&&B){
			cnt++;
			a/= 2;
			b/= 2;
		}else if (A){
			a/= 2;
		}else if (B){
			b/= 2;
		}else a-= b;
	}
	while (cnt){
		cnt--;
		a*= 2;
	}print(a);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	d[0]= 1;
	for (i= 1;i<lim;i++) d[i]= d[i-1]*10;
	scanf("%s",s+1);get(a);
	scanf("%s",s+1);get(b);
	gcd(a,b);
	return 0;
}

