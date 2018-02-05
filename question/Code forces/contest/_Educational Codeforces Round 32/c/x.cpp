#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 2e5;
int sum[30][maxn];
char s[maxn];
int n;
int idx(char c){
    return c-'a';
}
bool ok(int m){
    int b[30]={0};
    for (int i=1;i+m-1<=n;i++)
        for (int j=idx('a');j<=idx('z');j++)
            b[j]+= sum[j][i+m-1]-sum[j][i-1]>0;
    for (int j=idx('a');j<=idx('z');j++)
        if (b[j]==n-m+1)
            return true;
    return false;
}
int solve(){
    int l=0,r=n;
    while (l+1<r){
        int m= (l+r)/2;
        if (ok(m)) r=m;
        else l=m;
    }
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n= strlen(s+1);
	for (int i= 1;i<=n;i++){
        sum[idx(s[i])][i]++;
        for (int j= idx('a');j<=idx('z');j++)
            sum[j][i]+= sum[j][i-1];
	}
	int ans= solve();
	printf("%d",ans);
	return 0;
}
