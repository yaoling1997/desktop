#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int mo= 1e8;
const int maxn= 5005;
int f[2][maxn],sum[2][maxn];
char a[maxn],b[maxn];
int i,j,lena,lenb;
int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    lena= strlen(a+1);
    lenb= strlen(b+1);
    a[lena--]= '\0';
    b[lenb--]= '\0';
    sum[1][0]= 1;
    for (i= 0;i<=lenb;i++) sum[0][i]= 1;
    for (i= 1;i<=lena;i++){
        memset(f[i%2],0,sizeof(f[1]));
        memset(sum[i%2],0,sizeof(sum[1]));
        for (j= 1;j<=lenb;j++){
            if (a[i]==b[j]){
                f[i%2][j]= f[(i-1)%2][j-1]+1;
                if (f[(i-1)%2][j-1])
                    sum[i%2][j]= sum[(i-1)%2][j-1];
                else sum[i%2][j]= 1;
                if (f[(i-1)%2][j]==f[i%2][j])
                    sum[i%2][j]= (sum[i%2][j]+sum[(i-1)%2][j])%mo;
                if (f[i%2][j-1]==f[i%2][j])
                    sum[i%2][j]= (sum[i%2][j]+sum[i%2][j-1])%mo;
            }else {
                f[i%2][j]= max(f[(i-1)%2][j],f[i%2][j-1]);
                if (f[(i-1)%2][j]==f[i%2][j])
                    sum[i%2][j]= (sum[i%2][j]+sum[(i-1)%2][j])%mo;
                if (f[i%2][j-1]==f[i%2][j])
                    sum[i%2][j]= (sum[i%2][j]+sum[i%2][j-1])%mo;
                if (f[(i-1)%2][j-1]==f[i%2][j])
                    sum[i%2][j]= (sum[i%2][j]-sum[(i-1)%2][j-1])%mo;
            }
        }
    }
    printf("%d\n%d",f[lena%2][lenb],(sum[lena%2][lenb]+mo)%mo);
    return 0;
}
