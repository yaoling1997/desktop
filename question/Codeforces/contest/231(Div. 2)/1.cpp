#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 3001;
char s[maxn];
int len,ans,p,q,x,y,i,j;
int main()
{
	scanf("%s",s+1);
	len= strlen(s+1);
	for (i= 1;i<=len;i++){
		if (s[i]=='+') break;
		p++;
	}
	for (j= i+1;j<=len;j++){
		if (s[j]=='=') break;
		q++;
	}
	int g= len-j;
	if (p+q==g){
		printf("%s",s+1);
		return 0;
	}
	if (p+q+1==g-1){
		printf("%c",s[1]);
		for (i= 1;i<len;i++)
			printf("%c",s[i]);
		return 0;
	}
	if (p+q-1==g+1){
		if (p==1){
			for (i= 1;i<=len;i++){
				if (s[i+1]=='='){printf("=");break;}
				printf("%c",s[i]);
			}
			printf("%c",s[1]);
			for (j= i+2;j<=len;j++) printf("%c",s[i]);
		}else {
			for (i= 2;i<=len;i++)printf("%c",s[i]);
			printf("%c",s[1]);
		}
		return 0;
	}
	printf("Impossible");
	return 0;
}
