#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 300;
int map[maxn][maxn],c[maxn][maxn];
int n,m,i,j,x,y,ans,sum,D,xx,yy,now;
void init(){
    memset(map,0,sizeof(map));
    memset(c,0,sizeof(c));
    ans= sum= 0;
}
int main()
{
    while (scanf("%d%d",&n, &m)>0){
        init();
        for (i= 1;i<=n;i++)
            for (j= 1;j<=m;j++){
                scanf("%d",&c[i][j]);
                sum+= c[i][j];
            }
        if ((n&1)==1){
            printf("%d\n",sum);
            for (i= 1;i<=n;i++){
                if (i&1){
                    for (j= 1;j<m;j++)
                        printf("R");
                    if (i<n)
                        printf("D");
                }else {
                    for (j= 1;j<m;j++)
                        printf("L");
                    printf("D");
                }
            }
        }else if ((m&1)==1){
            printf("%d\n",sum);
            for (i= 1;i<=m;i++){
                if (i&1){
                    for (j= 1;j<n;j++)
                        printf("D");
                    if (i<m) printf("R");
                }else {
                    for (j= 1;j<n;j++)
                        printf("U");
                    printf("R");
                }
            }
        }else {
            x= 1;y= 2;
            for (i= 1;i<=n;i++)
                for (j= 1;j<=m;j++)
                    if ((i+j)%2==1){
                        if (c[i][j]<c[x][y]){
                            x= i;
                            y= j;
                        }
                    }
            printf("%d\n",sum-c[x][y]);
            D= 1;
            for (i= 1;i<=n;i++)
                if (i!=x && (i+1!=x)){
                    if (D){
                        for (j= 1;j<m;j++)
                            printf("R");
                        if (i!=n) printf("D");
                    }else {
                        for (j= 1;j<m;j++)
                            printf("L");
                        printf("D");
                    }
                    D^= 1;
                }else {
                    if (D){
                        xx= i;yy= 1;
                        now= 1;
                        while (yy<=m){
                            if (now){
                                if (xx+1==x&&yy==y){
                                    yy++;
                                    if (yy<=m)
                                        printf("R");
                                }else {
                                    printf("D");
                                    xx++;yy++;
                                    now^= 1;
                                    if (yy<=m) printf("R");
                                }
                            }else {
                                if (xx-1==x&&yy==y){
                                    yy++;
                                    if (yy<=m) printf("R");                                    
                                }else {
                                    printf("U");
                                    xx--;yy++;
                                    now^= 1;
                                    if (yy<=m) printf("R");
                                }
                            }
                        }
                    }else {
                        xx= i;yy= m;
                        now= 1;
                        while (yy>0){
                            if (now){
                                if (xx+1==x&&yy==y){
                                    yy--;
                                    if (yy>0) printf("L");
                                }else {
                                    printf("D");
                                    xx++;yy--;
                                    now^= 1;
                                    if (yy>0) printf("L");
                                }
                            }else {
                                if (xx-1==x&&yy==y){
                                    yy--;
                                    if (yy>0) printf("L");
                                }else {
                                    printf("U");
                                    xx--;yy--;
                                    now^= 1;
                                    if (yy>0) printf("L");
                                }
                            }
                        }                        
                    }D^= 1;i++;
                    if (i+1<=n) printf("D");
                }
        }
        printf("\n");
    }return 0;
}
