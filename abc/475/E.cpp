#include<bits/stdc++.h>
using namespace std;
int n, m, k, q;
string T;
int s[30005][205];
int cch[16161616][2];
int cnt1[16161616];
int nc;
void ip(int i) {
	int v = 0;
	for (int d = 0; d < k; ++d) {
		int b = s[i][d];
		if (b == 1) cnt1[v]++;
		int nv = cch[v][b];
		if (nv == -1) {
			nv = nc++;
			cch[nv][0] = cch[nv][1] = -1;
			cnt1[nv] = 0;
			cch[v][b] = nv;
		}
		v = nv;
	}
}
void ep(int i) {
	int v = 0;
	for (int d = 0; d < k; ++d) {
		int b = s[i][d];
		if (b == 1) cnt1[v]--;
		v = cch[v][b];
	}
}
bool ch(int person) {
	int v = 0;
	long long qn = 0;
	for (int d = 0; d < k; ++d) {
		int c = (v == -1 ? 0 : cnt1[v]);
		int kk;
		if (qn + c <= m) {
			qn += c;
			kk = 0;
		} else {
			kk = 1;
		}
		if (s[person][d] != kk) {
			return kk == 0;
		}
		if (v != -1) v = cch[v][kk];
	}
	return 0;
}
int main() {
	cin >> n >> m >> k;
	cin >> T;
	nc = 1;
	cch[0][0] = cch[0][1] = -1;
	cnt1[0] = 0;
	for (int i = 0; i < n; ++i) {
		string si;
		cin >> si;
		for (int j = 0; j < k; ++j) s[i][j] = (si[j] == T[j]) ? 1 : 0;
		ip(i);
	}
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		--i;
		--j;
		ep(i);
		s[i][j] ^= 1;
		ip(i);
		cout << (ch(i) ? "Yes" : "No") << '\n';
	}
}