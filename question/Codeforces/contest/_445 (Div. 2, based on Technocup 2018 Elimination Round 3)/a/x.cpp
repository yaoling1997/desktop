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
const int maxn= 5e5;
int a[maxn];
int n= 6,i,sum=0;
bool dfs(int o,int now,int s){
    if (now>3)
        return false;
    if (now==3){
        if (s==sum/2)
            return true;
        return false;
    }
    if (o>n)
        return false;
    return dfs(o+1,now,s)||dfs(o+1,now+1,s+a[o]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	for (i= 1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+= a[i];
    }
    if (sum&1){
        printf("NO");
    }else {
        bool bl= dfs(2,1,a[1]);
        printf("%s",bl?"YES":"NO");
    }
    return 0;
}
