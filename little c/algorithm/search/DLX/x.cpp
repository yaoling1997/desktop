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
const int maxn = 100;
const int maxnode = 100;
const int maxr = 100;
struct DLX {
	int n, sz;//�������ڵ�����
	int S[maxn];//���нڵ���(����������ڵ�)
	int row[maxnode], col[maxnode];//���ڵ����б��
	int L[maxnode], R[maxnode], U[maxnode], D[maxnode];//ʮ������
	int ansd, ans[maxr];//��
	void init(int n) {
		this->n = n;
		//����ڵ�,0��Ϊ����ͷ
		for (int i = 0; i <= n; i++) {
			U[i] = i;
			D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[n] = 0; L[0] = n;
		sz = n + 1;
		memset(S,0,sizeof(S));
	}
	void addRow(int r, vector<int> columns) {
		//r �к�,columns�����һ�е���Щ��Ϊ1
		int first = sz;
		for (int i = 0; i < columns.size(); i++) {
			int c = columns[i];
			L[sz] = sz - 1;
			R[sz] = sz + 1;
			D[sz] = c;
			U[sz] = U[c];
			D[U[c]] = sz;
			U[c] = sz;
			row[sz] = r;
			col[sz] = c;
			S[c]++;
			sz++;
		}
		R[sz - 1] = first;
		L[first] = sz - 1;		
	}
	//˳������A,������s�������Ԫ��
#define FOR(i,A,s) for(int i= A[s];i!=s;i=A[i])
	void remove(int c) {
		//�Ƴ����Ϊc���ڵ���
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		FOR(i,D,c)
			FOR(j, R, i) {
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--S[col[j]];
		}
	}
	void restore(int c) {
		//�ָ����c���ڵ���
		FOR(i,U,c)
			FOR(j, L, i) {
			++S[col[j]];
			U[D[j]] = j;
			D[U[j]] = j;
		}
		L[R[c]] = c;
		R[L[c]] = c;
	}
	//dΪ�ݹ����
	bool dfs(int d) {
		if (R[0] == 0) {
			//��ʾ�е�����ڵ㶼ɾ����
			ansd = d;//�ҵ���
			return true;//��¼��ĳ���
		}
		//��S��С����c
		int c = R[0];//��һ��δɾ����
		FOR(i, R, 0)
			if (S[i] < S[c])
				c = i;
		remove(c);//ɾ����c��
		FOR(i, D, c) {//�ýڵ�i�����и��ǵ�c��
			ans[d] = row[i];
			FOR(j, R, i)
				remove(col[j]);//ɾ���ڵ�i�������ܸ��ǵ�����������
			if (dfs(d + 1))
				return true;
			FOR(j, L, i)
				restore(col[j]);//�ָ��ڵ�i�������ܸ��ǵ�����������
		}
		restore(c);//�ָ���c��
		return false;
	}
	bool solve(vector<int> &v) {
		v.clear();
		if (!dfs(0))
			return false;
		for (int i = 0; i < ansd; i++)
			v.push_back(ans[i]);
		return true;
	}
};

int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	
}
