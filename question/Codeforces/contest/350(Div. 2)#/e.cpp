#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 6e5;
char c[maxn],s[maxn];
int left[maxn],right[maxn];
int n,m,i,j,now,p,q,o,r;
int val(char c){
	if (c=='(') return 1;
	else return -1;
}
void print(int o){
	while (o){
		printf("%c",c[o]);
		o= right[o];
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &m, &p);
	scanf("%s",c+1);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++){
		left[i]= i-1;
		right[i]= i+1;
	}
	right[n]= 0;
	left[0]= n;
	right[0]= 1;
	for (i= 1;i<=m;i++){
		if (s[i]=='L'){
			p= left[p];
		}else if (s[i]=='R'){
			p= right[p];
		}else {
			if (c[p]=='('){
				now= 1;
				q= p;
				o= left[q];
				while (now){
					p= right[p];
					now+= val(c[p]);
				}
				r= right[p];
				right[o]= r;
				left[r]= o;
				p= r;
				if (r==0)
					p= o;
			}else {
				now= -1;
				q= p;
				o= right[q];
				while (now){
					p= left[p];
					now+= val(c[p]);
				}
				r= left[p];
				left[o]= r;
				right[r]= o;
				p= o;
				if (o==0)
					p= r;				
			}
		}
	}
	print(right[0]);
	return 0;
}