#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<complex>
#include<cmath>
#include<vector>
using namespace std;
const double PI= acos(-1),eps= 1e-8;
const int maxn= 2000,maxm= 2e4;
typedef complex<double> CD;
vector<double> a,b;
double num[maxm];
int A[maxn];
int n,m,i,x,Max,k,cnt,len;
void FFT(vector<CD> &a,bool inv){
	int n= a.size(),i,j,k,step,Ek;
	for (i= j= 0;i<n;i++){
		if (j>i) swap(a[i],a[j]);
		k= n;
		while (j & (k>>= 1)) j&= ~k;
		j|= k;
	}
	double pi= inv ? -PI:PI;
	for (step= 1;step<n;step<<= 1){
		double alpha= pi/step;
		for (k= 0;k<step;k++){
			CD om= exp(CD(0,alpha*k));
			for (Ek= k;Ek<n;Ek+= step<<1){
				int Ok= Ek+step;
				CD t= om*a[Ok];
				a[Ok]= a[Ek]-t;
				a[Ek]+= t;
			}
		}
	}
	if (inv)
		for (i= 0;i<n;i++)
			a[i]/= n;
}
vector<double> operator *(vector<double> v1,vector<double> v2){
	int len1= v1.size(),len2= v2.size(),len= 2,i;
	while (len<len1+len2) len<<= 1;
	vector<CD> a(len,0),b(len,0);
	for (i= 0;i<len1;i++) a[i]= v1[i];
	for (i= 0;i<len2;i++) b[i]= v2[i];
	FFT(a,0);
	FFT(b,0);
	for (i= 0;i<len;i++) a[i]*= b[i];
	FFT(a,1);
	vector<double> res(len1+len2-1);
	for (i= 0;i<len1+len2-1;i++) res[i]= min((int)(a[i].real()+0.5),1);
	return res;
}
void look(vector<double> a){
	memset(num,0,sizeof(num));
	for (int i= 0;i<a.size();i++)
		num[i]= a[i];
}
void ksm(int k){
	while (k){
		if (k&1) b= b*a;
		k>>= 1;
		if (k) a= a*a;
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("3.out","w",stdout);
	scanf("%d%d",&n, &k);
	for (i= 1;i<=n;i++){
		scanf("%d",&A[i]);
		Max= max(A[i],Max);
	}
	for (i= 0;i<=Max;i++)
		a.push_back(0);
	for (i= 1;i<=n;i++)
		a[A[i]]= 1;
	b.push_back(1);
	ksm(k);
	//look(b);
	/*for (i= 1;i<k;i++){
		b= b*a;
		//look(b);
		}*/
	len= b.size();
	for (i= 1;i<len;i++)
		if (b[i]>0.5){
			cnt++;
			if (cnt>1) printf(" ");
			printf("%d",i);
		}
	return 0;
}
