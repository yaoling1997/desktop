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
	int n, sz;//列数，节点总数
	int S[maxn];//各列节点数(不包括虚拟节点)
	int row[maxnode], col[maxnode];//各节点行列编号
	int L[maxnode], R[maxnode], U[maxnode], D[maxnode];//十字链表
	int ansd, ans[maxr];//解
	void init(int n) {
		this->n = n;
		//虚拟节点,0号为链表头
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
		//r 行号,columns存放这一行的哪些列为1
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
	//顺着链表A,遍历除s外的其它元素
#define FOR(i,A,s) for(int i= A[s];i!=s;i=A[i])
	void remove(int c) {
		//移除标号为c所在的列
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
		//恢复标号c所在的列
		FOR(i,U,c)
			FOR(j, L, i) {
			++S[col[j]];
			U[D[j]] = j;
			D[U[j]] = j;
		}
		L[R[c]] = c;
		R[L[c]] = c;
	}
	//d为递归深度
	bool dfs(int d) {
		if (R[0] == 0) {
			//表示列的虚拟节点都删完了
			ansd = d;//找到解
			return true;//记录解的长度
		}
		//找S最小的列c
		int c = R[0];//第一个未删除列
		FOR(i, R, 0)
			if (S[i] < S[c])
				c = i;
		remove(c);//删除第c列
		FOR(i, D, c) {//用节点i所在行覆盖第c列
			ans[d] = row[i];
			FOR(j, R, i)
				remove(col[j]);//删除节点i所在行能覆盖的其它所有列
			if (dfs(d + 1))
				return true;
			FOR(j, L, i)
				restore(col[j]);//恢复节点i所在行能覆盖的其它所有列
		}
		restore(c);//恢复第c列
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
