#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e6;
char s[maxn];
int a[15],b[15],sub[maxn],ans[maxn],ans2[maxn];
int n,i,j,ls,x,L,la,bl,cnt;
bool oklen(int l){
	memset(b,0,sizeof(b));
	int x= l,y,cnt= 0;
	while (x){
		cnt++;
		y= x%10;
		x/= 10;
		b[y]++;
		if (b[y]>a[y]) return 0;
	}
	if (n-cnt==l){
		for (int i= 0;i<10;i++)
			a[i]-= b[i];
		return 1;
	}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n= strlen(s+1);
	for (i= 1;i<=n;i++){
		x= s[i]-'0';
		a[x]++;
	}
	scanf("%s",s+1);
	ls= strlen(s+1);
	for (i= 1;i<=ls;i++)
		sub[i]= s[i]-'0';
	for (L= 1;L<=1e6;L++)
		if (oklen(L)) break;
	for (i= 1;i<=ls;i++)
		a[sub[i]]--;
	for (i= 2;i<=ls;i++)
		if (sub[i]==0) cnt++;
		else break;
	if (sub[1]==0){
		for (i= 1;i<10;i++)
			if (a[i]){
				a[i]--;
				ans[++la]= i;
				break;
			}
		for (;a[0];a[0]--)
			ans[++la]= 0;
		for (i= 1;i<=ls;i++)
			ans[++la]= sub[i];
		for (i= 1;i<10;i++)
			for (;a[i];a[i]--)
				ans[++la]= i;			
	}else {
		bl= 0;
		for (i= 2;i<=ls;i++)
			if (sub[i]!=sub[i-1]){
				bl= i;
				break;
			}
		if (bl) bl= sub[i]<sub[1];
		if (bl){
			int co= 0;
			for (i= 1;i<sub[1];i++)
				if (a[i]){
					co= 1;
					a[i]--;
					ans[++la]= i;
					break;
				}
			if (!co){
				if (a[sub[1]]&&a[0]>cnt){
					a[sub[1]]--;
					a[0]--;
					ans[++la]= sub[1];
					ans[++la]= 0;
					co= 1;
				}else {
					for (i= 1;i<=ls;i++)
						ans[++la]= sub[i];					
				}
			}
			for (i= 0;i<sub[1];i++)
				for (;a[i];a[i]--)
					ans[++la]= i;
			if (co)
				for (i= 1;i<=ls;i++)
					ans[++la]= sub[i];
			for (i= sub[1];i<10;i++)
				for (;a[i];a[i]--)
					ans[++la]= i;						
		}else {
			int co= 0;
			for (i= 1;i<=sub[1];i++)
				if (a[i]){
					co= 1;
					a[i]--;
					ans[++la]= i;
					break;
				}
			if (!co)
				for (i= 1;i<=ls;i++)
					ans[++la]= sub[i];				
			for (i= 0;i<=sub[1];i++)
				for (;a[i];a[i]--)
					ans[++la]= i;
			if (co)
				for (i= 1;i<=ls;i++)
					ans[++la]= sub[i];
			for (i= sub[1]+1;i<10;i++)
				for (;a[i];a[i]--)
					ans[++la]= i;			
		}
	}
	for (i= 1;i<=la;i++)
		printf("%d",ans[i]);
	return 0;
}