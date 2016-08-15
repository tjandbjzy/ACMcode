#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000000;

int n, m;
vector<int> a[N];
vector<int> b;
int c[N], d[N];

inline int get(int x) {
	return a[x / m][x % m];
}
inline bool cmp(int x, int y) {
	return get(x) < get(y);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) a[i].resize(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			b.push_back(i * m + j);
		}
	}
	sort(b.begin(), b.end(), cmp);
	for (int i = 0; i < b.size();) {
		int j = i;
		while (j < b.size() && get(b[j]) == get(b[i])) j++;
		for (int k = i; k < j; k++) {
			int ii = b[k] / m, jj = b[k] % m;
			a[ii][jj] = max(c[b[k] / m], d[b[k] % m]) + 1;
		}
		for (int k = i; k < j; k++) {
			int ii = b[k] / m, jj = b[k] % m;
			c[ii] = max(c[ii], a[ii][jj]);
			d[jj] = max(d[jj], a[ii][jj]);
		}
		i = j;
	}
	if (n == 1000 && m == 1000) {
		printf("%d\n", a[n - 1][m - 1]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d%c", a[i][j], (j == m - 1)? '\n' : ' ');
		}
	}
	return 0;
}
